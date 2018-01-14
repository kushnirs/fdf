/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_polygon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergee <sergee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 02:11:20 by sergee            #+#    #+#             */
/*   Updated: 2018/01/15 01:34:54 by sergee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	*z_buff(t_mlx *data)
{
	int i;

	i = -1;
	while (++i < HIGH * WIDTH)
		data->data_adr[i] =	data->z_buff[i].color;
	ft_bzero(data->z_buff, HIGH * WIDTH * sizeof(t_coord));
	return (data->image);
}

static void	ft_draw_line(t_mlx *data, t_coord p0, t_coord p1)
{
	double		t;
	double		k;
	t_coord		new;

	k = 1.0 / sqrt((pow((p1.x - p0.x), 2) + pow((p1.y - p0.y), 2)));
	t = 0;
	while (t <= 1)
	{
		new.y = p0.y + t * (p1.y - p0.y) - data->move_y;
		new.x = p0.x + t * (p1.x - p0.x) - data->move_x;
		new.z = p0.z + t * (p1.z - p0.z);
		if (new.x >= 0 && new.x <= WIDTH && new.y >= 0 && new.y <= HIGH
			&& (!data->z_buff[(int)new.x + (int)new.y * WIDTH].color
				|| new.z > data->z_buff[(int)new.x + (int)new.y * WIDTH].z))
		{
			data->z_buff[(int)new.x + (int)new.y * WIDTH].z = new.z;
			data->z_buff[(int)new.x + (int)new.y * WIDTH].color =
			parse_color(p0.color, p1.color, t);
		}
		t += k;
	}
}

static void	ft_swap(t_coord *a, t_coord *b)
{
	t_coord *tmp;

	tmp = a;
	a = b;
	b = tmp;
}

static void	ft_draw_polygon_triangle(t_mlx *data, t_coord p0,
												t_coord p1, t_coord p2)
{
	double	t;
	double	k;
	t_coord	tmp;

	ft_draw_line(data, p0, p1);
	ft_draw_line(data, p0, p2);
	if (data->p)
	{
		ft_draw_line(data, p2, p1);
		p1.y < p0.y ? ft_swap(&p1, &p0) : 0;
		p2.y < p0.y ? ft_swap(&p2, &p0) : 0;
		p2.y < p1.y ? ft_swap(&p2, &p1) : 0;
		k = 0.5 / sqrt((pow((p2.x - p0.x), 2) + pow((p2.y - p0.y), 2)));
		t = 0;
		while (t <= 1)
		{
			tmp.y = p0.y + t * (p2.y - p0.y);
			tmp.x = p0.x + t * (p2.x - p0.x);
			tmp.color = parse_color(p0.color, p2.color, t);
			ft_draw_line(data, p1, tmp);
			t += k;
		}
	}
}

void		ft_draw_polygon(t_mlx *data)
{
	int		x;
	int		y;
	t_coord **arr;

	ft_bzero(data->data_adr, HIGH * data->sl);
	data->start.x = data->column / 2 * (-data->size);
	data->start.y = data->row / 2 * (-data->size);
	arr = data->arr;
	x = -1;
	while (++x < data->row - 1)
	{
		y = -1;
		while (++y < data->column - 1)
		{
			ft_draw_polygon_triangle(data,
				ft_conversion_xyz(data, arr[x][y]),
				ft_conversion_xyz(data, arr[x][y + 1]),
				ft_conversion_xyz(data, arr[x + 1][y]));
			ft_draw_polygon_triangle(data,
				ft_conversion_xyz(data, arr[x + 1][y + 1]),
				ft_conversion_xyz(data, arr[x][y + 1]),
				ft_conversion_xyz(data, arr[x + 1][y]));
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, z_buff(data), 0, 0);
}
