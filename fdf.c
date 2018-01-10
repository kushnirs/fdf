/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:13:45 by skushnir          #+#    #+#             */
/*   Updated: 2018/01/10 20:42:19 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_action(int key, t_mlx *data)
{
	char	e;

	mlx_clear_window(data->mlx, data->win);
	e = 0;
	key == ESC ? exit(0) : 0;
	key == UP || key == DOWN ? ft_up_down(key, data) : 0;
	key == LEFT || key == RIGHT ? ft_left_right(key, data) : 0;
	key == B_A && ++e ? data->rot.ry -= 5 : 0;
	key == B_W && ++e ? data->rot.rx -= 5 : 0;
	key == B_D && ++e ? data->rot.ry += 5 : 0;
	key == B_S && ++e ? data->rot.rx += 5 : 0;
	e ? ft_conversion_xyz(data) : 0;
	return (0);
}

int main(int ar, char **av)
{
	int		fd;
	t_mlx	data;
	
	ar != 2 ?
	exit(write(1, "Usage : ./fdf <filename>[ case_size z_size ]\n", 46)) : 0;
	if ((fd = open(av[1], O_RDONLY)) == -1)
		exit(ft_printf("No file %s\n", av[1]));
	data.move_x = 0;
	data.move_y = 0;
	data.rot.rx = -60;
	data.rot.ry = 50;
	data.rot.rz = 0;
	read_coordinate(fd, av[1], &data);
	// printf("\n");
	// for(int x = 0; x<11; x++)
	// {
	// 	for (int y = 0; y<19; y++)
	// 	{
	// 		printf("|%8ld| ", data.arr[x][y].color);
	// 		// printf("%.0f| ", data.arr[x][y].y);
	// 		// printf("|%3.0f|  ", data.arr[x][y].z);
	// 	}
	// 	printf("\n");
	// }
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HIGH, "fdf");
	ft_conversion_xyz(&data);
	mlx_key_hook(data.win, &key_action, &data);
	mlx_hook(data.win, 17, 0, &close_window , &data);
	mlx_loop(data.mlx);
	return (0);
}
