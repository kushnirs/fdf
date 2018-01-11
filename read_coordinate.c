/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_coordinate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 15:55:45 by skushnir          #+#    #+#             */
/*   Updated: 2018/01/11 21:15:34 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	parse_coordinate(int c, t_mlx *data, char **coord)
{
	int			x;
	static int	y = 0;

	!data->column ? data->column = c : 0;
	data->column != c ?
		exit(write(1, "Found wrong line length. Exiting.\n", 34)) : 0;
	data->arr[y] = (t_coord *)ft_memalloc(sizeof(t_coord) * (c + 1));
	x = -1;
	while (coord[++x])
	{
		data->arr[y][x].x = x;
		data->arr[y][x].y = y;
		data->arr[y][x].z = ft_atoi(coord[x]);
		data->arr[y][x].color = (ft_strchr(coord[x], ',') ?
		ft_hex_to_dec(ft_strchr(coord[x], ',') + 1) : 0xFFFFFF);
		ft_memdel((void **)&coord[x]);
	}
	ft_memdel((void **)&coord);
	y++;
}

void		read_coordinate(int fd, char *av, t_mlx *data)
{
	int		i;
	char	*line;
	char	**coord;

	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		ft_memdel((void **)&line);
		data->row++;
	}
	close(fd);
	data->arr = (t_coord **)ft_memalloc(sizeof(t_coord *) * (data->row + 1));
	data->arr[data->row] = NULL;
	(fd = open(av, O_RDONLY)) == -1 ? exit(ft_printf("No file %s\n", av)) : 0;
	coord = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		coord = ft_strsplit(line, ' ');
		i = 0;
		while (coord[i])
			i++;
		parse_coordinate(i, data, coord);
		ft_memdel((void **)&line);
	}
	close(fd);
}
