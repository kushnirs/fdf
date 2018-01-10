/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 21:58:17 by sergee            #+#    #+#             */
/*   Updated: 2018/01/10 20:39:58 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static unsigned int	parse_color(int c1, int c2, double t)
{
	unsigned char dr;
	unsigned char dg;
	unsigned char db;

	dr = (1 - t) * (double)(c1 / 0x10000 % 256) + t *  (double)(c2 / 0x10000 % 256);
	dg = (1 - t) * (double)(c1 / 0x100 % 256) + t *  (double)(c2 / 0x100 % 256);
	db = (1 - t) * (double)(c1 % 256) + t * (double)(c2 % 256);

	return (dr * 0x10000 + dg * 0x100 + db);
}
void	ft_draw_line(t_mlx *data, t_coord *p0, t_coord *p1)
{
	double	t;
	double	k;
	double	n_x;
	double	n_y;

	mlx_clear_window(data->mlx, data->win);
	k = 1.0 / sqrt((pow((p1->x - p0->x), 2) + pow((p1->y - p0->y), 2)));
	t = 0;
	while (t <= 1)
	{
		n_y = p0->y + t * (p1->y - p0->y);
		n_x = p0->x + t * (p1->x - p0->x);
		mlx_pixel_put(data->mlx, data->win, n_x, n_y, parse_color(p0->color, p1->color, t));
		t += k;
	}
}

void	ft_draw_fdf(t_mlx *data, t_coord **arr)
{
	int		x;
	int		y;
	t_coord	p[3];

	x = -1;
	while (++x < data->row)
	{
		y = -1;
		while (++y < data->column)
		{
			p[0]= arr[x][y];
			if (y + 1 < data->column)
			{
				p[2] = arr[x][y + 1];
				ft_draw_line(data, &p[0], &p[2]);
			}
			if (x + 1 < data->row)
			{
				p[1] = arr[x + 1][y];
				ft_draw_line(data, &p[0], &p[1]);
			}
		}
	}
	ft_memdel((void **)arr);
}

void	ft_conversion_xyz(t_mlx *data)
{
	int		x;
	int		y;
	t_coord	p[3];
	t_coord	**tmp;
	t_coord **arr;

	tmp = (t_coord **)ft_memalloc(sizeof(t_coord *) * (data->row + 1));
	tmp[data->row] = NULL;
	x = -1;
	while (++x < data->row)
		tmp[x] = (t_coord *)ft_memalloc(sizeof(t_coord) * (data->column + 1));
	tmp[x] = NULL;
	arr = data->arr;
	x = -1;
	while (++x < data->row)
	{
		y = -1;
		while (++y < data->column)
		{
			p[0].x = arr[x][y].x;
			p[0].y = arr[x][y].y * cos(PI * data->rot.rx / 180) + arr[x][y].z * sin(PI * data->rot.rx / 180);
			p[0].z = arr[x][y].z * cos(PI * data->rot.rx / 180) - arr[x][y].y * sin(PI * data->rot.rx / 180);
			p[1].x = p[0].x * cos(PI * data->rot.ry / 180) + p[0].z * sin(PI * data->rot.ry / 180);
			p[1].y = p[0].y;
			p[1].z = p[0].z * cos(PI * data->rot.ry / 180) - p[0].x * sin(PI * data->rot.ry / 180);
			p[2].x = WIDTH / 2 + p[1].x * cos(PI * data->rot.rz / 180) - p[1].y * sin(PI * data->rot.rz / 180);
			p[2].y = HIGH / 2 + p[1].x * sin(PI * data->rot.rz / 180) + p[1].y * cos(PI * data->rot.rz / 180);
			p[2].z = p[1].z;
			p[2].color = arr[x][y].color;
			tmp[x][y] = p[2];
		}
	}
	ft_draw_fdf(data, tmp);
}
