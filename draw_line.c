/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 21:58:17 by sergee            #+#    #+#             */
/*   Updated: 2018/01/09 15:29:50 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line(t_mlx *data, double x0, double x1, double y0, double y1)
{
	double	t;
	double	k;
	double	n_x;
	double	n_y;

	t = 0;
	k = 1.0 / sqrt((pow((x1 - x0), 2) + pow((y1 - y0), 2)));
	t = 0;
	while (t <= 1)
	{
		n_y = y0 + t * (y1 - y0);
		n_x = x0 + t * (x1 - x0);
		mlx_pixel_put(data->mlx, data->win, n_x, n_y, 0x00FFFFFF);
		t += k;
	}
}

void	ft_draw_fdf(t_mlx *data)
{
	int	x;
	int	y;
	t_coord **arr;

	arr = data->arr;
	x = -1;
	while (++x < data->row)
	{
		y = -1;
		while (++y < data->column)
		{
			if (y + 1 < data->column)
				ft_draw_line(data, arr[x][y].x, arr[x][y + 1].x, arr[x][y].y, arr[x][y + 1].y);
			if (x + 1 < data->row)
				ft_draw_line(data, arr[x][y].x, arr[x + 1][y].x, arr[x][y].y, arr[x + 1][y].y);
		}
	}
}

void	ft_conversion_xyz(t_mlx *data)
{
	int	x;
	int	y;
	int	c_x;
	int	c_y;

	t_coord **arr;
	arr = data->arr;
	c_x = WIDTH / 2;
	c_y = HIGH / 2;
	x = -1;
	while (++x < data->row)
	{
		y = -1;
		while (++y < data->column)
		{
			double x_ = arr[x][y].x;

			arr[x][y].x = arr[x][y].x * cos(PI * -45 / 180) - arr[x][y].z * sin(PI * -45 / 180);
			arr[x][y].y = arr[x][y].y * cos(PI * 45 / 180) -
			(arr[x][y].z * cos(PI * -45 / 180) + x_ * sin(PI * -45 / 180)) * sin(PI * 45 / 180);
			x_ = arr[x][y].x;
			arr[x][y].x =  c_x + arr[x][y].x * cos(PI * -60 / 180) - arr[x][y].y * sin(PI * -60 / 180);
			arr[x][y].y =  c_y + x_ * sin(PI * -60 / 180) + arr[x][y].y * cos(PI * -60 / 180);
		}
	}
}
