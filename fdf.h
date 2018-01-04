/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:04:48 by skushnir          #+#    #+#             */
/*   Updated: 2018/01/04 19:31:15 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdio.h>
#include "libft/libft.h"
#include "libft/printf/ft_printf.h"

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

int		read_coordinate(int fd, char *av);
int		close_window(int key, t_mlx *new);
# endif