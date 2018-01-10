/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergee <sergee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 21:58:17 by sergee            #+#    #+#             */
/*   Updated: 2018/01/10 12:14:32 by sergee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line(t_mlx *data, t_coord *p0, t_coord *p1)
{
	double	t;
	double	k;
	double	n_x;
	double	n_y;

	k = 1.0 / sqrt((pow((p1->x - p0->x), 2) + pow((p1->y - p0->y), 2)));
	t = 0;
	while (t <= 1)
	{
		n_y = p0->y + t * (p1->y - p0->y);
		n_x = p0->x + t * (p1->x - p0->x);
		mlx_pixel_put(data->mlx, data->win, n_x, n_y, p0->color);
		t += k;
	}
}

void	ft_draw_fdf(t_mlx *data)
{
	int		x;
	int		y;
	t_coord	p[3];
	t_coord **arr;

	arr = data->arr;
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
}

void	ft_conversion_xyz(t_mlx *data)
{
	int		x;
	int		y;
	double	x_;

	t_coord **arr;
	arr = data->arr;
	x = -1;
	while (++x < data->row)
	{
		y = -1;
		while (++y < data->column)
		{
			x_ = arr[x][y].x;
			arr[x][y].x = arr[x][y].x * cos(PI * -45 / 180) - arr[x][y].z * sin(PI * -45 / 180);
			arr[x][y].y = arr[x][y].y * cos(PI * 45 / 180) -
			(arr[x][y].z * cos(PI * -45 / 180) + x_ * sin(PI * -45 / 180)) * sin(PI * 45 / 180);
			x_ = arr[x][y].x;
			arr[x][y].x =  WIDTH / 2 + arr[x][y].x * cos(PI * -60 / 180) - arr[x][y].y * sin(PI * -60 / 180);
			arr[x][y].y =  HIGH / 2 + x_ * sin(PI * -60 / 180) + arr[x][y].y * cos(PI * -60 / 180);
		}
	}
}
