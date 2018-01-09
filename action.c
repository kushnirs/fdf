/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 09:40:04 by skushnir          #+#    #+#             */
/*   Updated: 2018/01/09 14:35:28 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int close_window(t_mlx *data)
{
	ft_memdel((void **)&data);
	exit(0);
	return (0);
}

int	ft_up_down(int key, t_mlx *data)
{
	key = 0;
	mlx_clear_window(data->mlx, data->win);
	return (0);
}

int	ft_left_right(int key, t_mlx *data)
{
	key = 0;
	mlx_clear_window(data->mlx, data->win);
	return (0);
}