/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:13:45 by skushnir          #+#    #+#             */
/*   Updated: 2018/01/09 11:48:14 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_action(int key, t_mlx *new)
{
	key == ESC ? exit(0) : 0;
	key == UP || key == DOWN ? ft_up_down(key, new) : 0;
	key == LEFT || key == RIGHT ? ft_left_right(key, new) : 0;	
	return (0);
}

int main(int ar, char **av)
{
	int		fd;
	t_mlx	data;
	t_coord	**arr;
	
	ar != 2 ?
	exit(write(1, "Usage : ./fdf <filename>[ case_size z_size ]\n", 46)) : 0;
	if ((fd = open(av[1], O_RDONLY)) == -1)
		exit(ft_printf("No file %s\n", av[1]));
	arr = NULL;
	arr = read_coordinate(fd, av[1], arr, &data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HIGH, "fdf");
	ft_conversion_xyz(arr, &data);
	ft_draw_fdf(arr, &data);
	// for(int x = 0; x<19; x++)
	// {
	// 	for (int y = 0; y<10; y++)
	// 	{
	// 		// printf("|%.0f ", arr[x][y].x);
	// 		// printf("%.0f ", arr[x][y].y);
	// 		printf("|%3.0f|  ", arr[x][y].z);
	// 	}
	// 	printf("\n");
	// }
	
	mlx_key_hook(data.win, &key_action, &data);
	mlx_loop(data.mlx);
	return (0);
}
