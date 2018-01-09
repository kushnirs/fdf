/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:04:48 by skushnir          #+#    #+#             */
/*   Updated: 2018/01/09 11:47:08 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdio.h>
#include <math.h>
#include "mlx.h"
#include "libft/libft.h"
#include "libft/printf/ft_printf.h"

# define HIGH	1000
# define WIDTH	1000
# define UP		126
# define DOWN	125
# define LEFT	123
# define RIGHT	124
# define SIZE	20
# define ESC	53
# define PI		3.14159265358979323846

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	int		row;
	int		column;
}				t_mlx;

typedef struct	s_coord
{
	double	x;
	double	y;
	double	z;
}				t_coord;

t_coord	**read_coordinate(int fd, char *av, t_coord **arr, t_mlx *data);
void	ft_draw_line(t_mlx *new, double x0, double x1, double y0, double y1);
void	ft_draw_fdf(t_coord **arr, t_mlx *data);
void	ft_conversion_xyz(t_coord **arr, t_mlx *data);
int		key_action(int key, t_mlx *new);
int		ft_up_down(int key, t_mlx *data);
int		ft_left_right(int key, t_mlx *data);
# endif