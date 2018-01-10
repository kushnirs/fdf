/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:13:45 by skushnir          #+#    #+#             */
/*   Updated: 2018/01/10 21:20:43 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int close_window(t_mlx *data)
{
	data = NULL;
	exit(0);
	return (0);
}

int	key_action(int key, t_mlx *data)
{
	key == ESC ? exit(0) : 0;
	key == UP ? data->move_y += 50 : 0;
	key == DOWN ? data->move_y += -50 : 0;
	key == RIGHT ? data->move_x += -50 : 0;
	key == LEFT ? data->move_x += +50 : 0;
	key == B_A ? data->rot.ry -= 5 : 0;
	key == B_W ? data->rot.rx -= 5 : 0;
	key == B_D ? data->rot.ry += 5 : 0;
	key == B_S ? data->rot.rx += 5 : 0;
	ft_draw_fdf(data);
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
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HIGH, "fdf");
	ft_draw_fdf(&data);
	mlx_key_hook(data.win, &key_action, &data);
	mlx_hook(data.win, 17, 0, &close_window , &data);
	mlx_loop(data.mlx);
	return (0);
}
