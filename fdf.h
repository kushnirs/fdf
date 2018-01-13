/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:04:48 by skushnir          #+#    #+#             */
/*   Updated: 2018/01/13 12:15:50 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <math.h>
# include "minilibx/mlx.h"
# include "libft/printf/ft_printf.h"

# define HIGH	1000
# define WIDTH	1000
# define B_A	0
# define B_W	13
# define B_D	2
# define B_S	1
# define B_Q	12
# define B_E    14
# define B_PLUS 69
# define B_MIN  78
# define M_UP   5
# define M_DOWN 4
# define M_L	1
# define M_R	2
# define UP		126
# define DOWN	125
# define LEFT	123
# define RIGHT	124
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
	void	*image;
	int		bpp;
	int		sl;
	int		endian;
	t_ui	*data_adr;
	double	size;
	int		row;
	int		column;
	int		move_x;
	int		move_y;
	int		p;
	t_rot	rot;
	t_coord	centre;
	t_coord	start;
	t_coord	**arr;
}				t_mlx;

void			read_coordinate(int fd, char *av, t_mlx *data);
void			ft_draw_polygon(t_mlx *data);
t_coord			ft_conversion_xyz(t_mlx *data, t_coord rot);
int				key_action(int key, t_mlx *new);
int				mouse_action(int button, int x, int y, t_mlx *data);
unsigned int	parse_color(int c1, int c2, double t);
int				close_window(t_mlx *data);
#endif
