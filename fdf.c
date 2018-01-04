/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:13:45 by skushnir          #+#    #+#             */
/*   Updated: 2018/01/04 20:25:25 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include "mlx.h"

int	close_window(int key, t_mlx *new)
{
	if (key == 53)
	{
		mlx_destroy_window(new->mlx, new->win);
		exit (0);
	}
	return (0);
}

int main(int ar, char **av)
{
	int		fd;
	
	ar != 2 ?
	exit(write(1, "Usage : ./fdf <filename>[ case_size z_size ]\n", 46)) : 0;
	if ((fd = open(av[1], O_RDONLY)) == -1 || read_coordinate(fd, av[1]) == -1)
		exit(ft_printf("No file %s\n", av[1]));
	// double n_x;
	// double n_y;
	// double x[2];
	// double y[2];

	// t_mlx new;
	// x[0] = -50;
	// y[0] = -200;
	// x[1] = 60;
	// y[1] = 240;
	// x[0] += 250;
	// y[0] = 250 - y[0];
	// x[1] += 250;
	// y[1] = 250 - y[1];

	// double t = 0;
	// double k = 1.0 / sqrt((pow((x[1] - x[0]), 2) + pow((y[1] - y[0]), 2)));
	// new.mlx = mlx_init();
	// new.win = mlx_new_window(new.mlx, 500, 500, "fdf");
	// for (int k = 0; k < 500; k++)
	// 	mlx_pixel_put(new.mlx, new.win, 250, k, 0x00FFFFFF);
	// for (int k = 0; k < 500; k++)
	// 	mlx_pixel_put(new.mlx, new.win, k, 250, 0x00FFFFFF);
	// for (t = 0; t <= 1; t += k)
	// {
	// 	n_y = y[0] + t * (y[1] - y[0]);
	// 	n_x = x[0] + t * (x[1] - x[0]);
	// 	mlx_pixel_put(new.mlx, new.win, n_x, n_y, 0x00FFFFF);
	// }
	// mlx_key_hook(new.win, &close_window, &new);
	// mlx_loop(new.mlx);
	return (0);
}
// gcc fdf.c -lmlx -framework OpenGl -framework AppKit
// gcc fdf.c read_coordinate.c libft/libftprintf.a -lmlx -framework OpenGl -framework AppKit