/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergee <sergee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 09:40:04 by skushnir          #+#    #+#             */
/*   Updated: 2018/01/10 12:14:35 by sergee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int close_window(t_mlx *data)
{
	data = NULL;
	exit(0);
	return (0);
}

int	ft_up_down(int key, t_mlx *data)
{
	int		x;
	int		y;
	t_coord **arr;

	arr = data->arr;
	data->move_x = 0;
	key == UP ? data->move_y = -50 : 0;
	key == DOWN ? data->move_y = 50 : 0;
	x = -1;
	while (++x < data->row)
	{
		y = -1;
		while (++y < data->column)
		{
			arr[x][y].x += data->move_x;
			arr[x][y].y += data->move_y;
		}
	}
	mlx_clear_window(data->mlx, data->win);
	ft_draw_fdf(data);
	return (0);
}

int	ft_left_right(int key, t_mlx *data)
{
	int		x;
	int		y;
	t_coord **arr;

	arr = data->arr;
	data->move_y = 0;
	key == RIGHT ? data->move_x = 50 : 0;
	key == LEFT ? data->move_x = -50 : 0;
	x = -1;
	while (++x < data->row)
	{
		y = -1;
		while (++y < data->column)
		{
			arr[x][y].x += data->move_x;
			arr[x][y].y += data->move_y;
		}
	}
	mlx_clear_window(data->mlx, data->win);
	ft_draw_fdf(data);
	return (0);
}