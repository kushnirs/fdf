/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:13:45 by skushnir          #+#    #+#             */
/*   Updated: 2018/01/02 21:09:10 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
	t_mlx new;

	new.mlx = mlx_init();
	new.win = mlx_new_window(new.mlx, 400, 400, "fdf");
	for (int x = 0; x < 225; x++)
		for (int y = 0; y < 225; y+=3)
			mlx_pixel_put(new.mlx, new.win, x, y, 0x00FFFFFF);
	mlx_key_hook(new.win, &close_window, &new);
	mlx_loop(new.mlx);
	return (0);
}
// gcc main.c -lmlx -framework OpenGl -framework AppKit