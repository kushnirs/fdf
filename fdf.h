/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:04:48 by skushnir          #+#    #+#             */
/*   Updated: 2018/01/10 18:50:03 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdio.h>
#include <math.h>
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "libft/printf/ft_printf.h"

# define HIGH	1000
# define WIDTH	1000
# define B_A	0
# define B_W	13
# define B_D	2
# define B_S	1
# define UP		126
# define DOWN	125
# define LEFT	123
# define RIGHT	124
# define SIZE	20
# define ESC	53
# define PI		3.14159265358979323846

typedef struct	s_coord
{
	double	x;
	double	y;
	double	z;
	long	color;
}				t_coord;

typedef struct	s_rot
{
	double	rx;
	double	ry;
	double	rz;
}				t_rot;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	int		size;
	int		row;
	int		column;
	int		move_x;
	int		move_y;
	t_rot	rot;
	t_coord	start;
	t_coord	**arr;
}				t_mlx;

void	read_coordinate(int fd, char *av, t_mlx *data);
void	ft_draw_line(t_mlx *data, t_coord *p0, t_coord *p1);
void	ft_draw_fdf(t_mlx *data, t_coord **tmp);
void	ft_conversion_xyz(t_mlx *data);
int		key_action(int key, t_mlx *new);
int		ft_up_down(int key, t_mlx *data);
int		ft_left_right(int key, t_mlx *data);
int 	rotation(t_mlx *data);
int		close_window(t_mlx *data);
# endif