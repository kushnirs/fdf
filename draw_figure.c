/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergee <sergee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 21:58:17 by sergee            #+#    #+#             */
/*   Updated: 2018/01/13 02:15:45 by sergee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int		parse_color(int c1, int c2, double t)
{
	unsigned char dr;
	unsigned char dg;
	unsigned char db;

	dr = (1 - t) * (double)(c1 / 0x10000 % 256) +
		t * (double)(c2 / 0x10000 % 256);
	dg = (1 - t) * (double)(c1 / 0x100 % 256) + t * (double)(c2 / 0x100 % 256);
	db = (1 - t) * (double)(c1 % 256) + t * (double)(c2 % 256);
	return (dr * 0x10000 + dg * 0x100 + db);
}

void				ft_draw_line(t_mlx *data, t_coord p0, t_coord p1)
{
	double	t;
	double	k;
	double	n_x;
	double	n_y;

	k = 1.0 / sqrt((pow((p1.x - p0.x), 2) + pow((p1.y - p0.y), 2)));
	t = 0;
	while (t <= 1)
	{
		n_y = p0.y + t * (p1.y - p0.y) - data->move_y;
		n_x = p0.x + t * (p1.x - p0.x) - data->move_x;
		if (n_x >= 0 && n_x <= WIDTH && n_y >= 0 && n_y <= HIGH)
			data->data_adr[(int)n_x + (int)n_y * data->sl / 4] =
				parse_color(p0.color, p1.color, t);
		t += k;
	}
}

void				ft_draw_fdf(t_mlx *data)
{
	int		x;
	int		y;
	t_coord **arr;

	ft_bzero(data->data_adr, HIGH * data->sl);
	data->start.x = data->column / 2 * (-data->size);
	data->start.y = data->row / 2 * (-data->size);
	arr = data->arr;
	x = -1;
	while (++x < data->row)
	{
		y = -1;
		while (++y < data->column)
		{
			if (y + 1 < data->column)
				ft_draw_line(data, ft_conversion_xyz(data, arr[x][y]),
					ft_conversion_xyz(data, arr[x][y + 1]));
			if (x + 1 < data->row)
				ft_draw_line(data, ft_conversion_xyz(data, arr[x][y]),
					ft_conversion_xyz(data, arr[x + 1][y]));
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
}

t_coord				ft_conversion_xyz(t_mlx *data, t_coord rot)
{
	t_coord	p[3];
	double	func[6];

	rot.x = rot.x * data->size + data->start.x;
	rot.y = rot.y * data->size + data->start.y;
	rot.z = rot.z * data->size / 2;
	func[0] = cos(PI * data->rot.rx / 180);
	func[1] = sin(PI * data->rot.rx / 180);
	func[2] = cos(PI * data->rot.ry / 180);
	func[3] = sin(PI * data->rot.ry / 180);
	func[4] = cos(PI * data->rot.rz / 180);
	func[5] = sin(PI * data->rot.rz / 180);
	p[0].x = rot.x;
	p[0].y = rot.y * func[0] + rot.z * func[1];
	p[0].z = rot.z * func[0] - rot.y * func[1];
	p[1].x = p[0].x * func[2] + p[0].z * func[3];
	p[1].y = p[0].y;
	p[1].z = p[0].z * func[2] - p[0].x * func[3];
	p[2].x = WIDTH / 2 + p[1].x * func[4] - p[1].y * func[5];
	p[2].y = HIGH / 2 + p[1].x * func[5] + p[1].y * func[4];
	p[2].z = p[1].z;
	p[2].color = rot.color;
	return (p[2]);
}
