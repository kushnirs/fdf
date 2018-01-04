/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:13:45 by skushnir          #+#    #+#             */
/*   Updated: 2018/01/04 15:51:09 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "mlx.h"

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

int	close_window(int key, t_mlx *new)
{
	if (key == 53)
	{
		mlx_destroy_window(new->mlx, new->win);
		exit (0);
	}
	return (0);
}

int main()
{
	double n_x;
	double n_y;
	double x[2];
	double y[2];

	t_mlx new;
	x[0] = -50;
	y[0] = -200;
	x[1] = 60;
	y[1] = 240;
	x[0] += 250;
	y[0] = 250 - y[0];
	x[1] += 250;
	y[1] = 250 - y[1];
	// if (x[0] > x[1])
	// {
	// 	int t;

	// 	t = x[0];
	// 	x[0] = x[1];
	// 	x[1] = t;
	// 	t = y[0];
	// 	y[0] = y[1];
	// 	y[1] = t;

	// }
	double t = 0;
	double k = 1.0 / sqrt((pow((x[1] - x[0]), 2) + pow((y[1] - y[0]), 2)));
	// printf("%f\n", t);
	//int a = ((y[1] - y[0]))/((x[1] - x[0]));
	// n_y = y[0];
	new.mlx = mlx_init();
	new.win = mlx_new_window(new.mlx, 500, 500, "fdf");
	for (int k = 0; k < 500; k++)
		mlx_pixel_put(new.mlx, new.win, 250, k, 0x00FFFFFF);
	for (int k = 0; k < 500; k++)
		mlx_pixel_put(new.mlx, new.win, k, 250, 0x00FFFFFF);
	for (t = 0; t <= 1; t += k)
	{
		n_y = y[1] + t * (y[0] - y[1]);
		n_x = x[1] + t * (x[0] - x[1]);
		mlx_pixel_put(new.mlx, new.win, n_x, n_y, 0x00FFFFF);
	}
	mlx_key_hook(new.win, &close_window, &new);
	mlx_loop(new.mlx);
	return (0);
}
// gcc main.c -lmlx -framework OpenGl -framework AppKit