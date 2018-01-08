/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_coordinate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergee <sergee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 15:55:45 by skushnir          #+#    #+#             */
/*   Updated: 2018/01/08 23:03:52 by sergee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coord	**parse_coordinate(int y, t_mlx *data, char **coord, t_coord **arr)
{
	int	x;

	!data->column ? data->column = y : 0;
	data->column != y ?
	exit(write(1, "Found wrong line length. Exiting.\n", 34)) : 0;
	y = 0;
	while (arr[y])
		y++;
	arr[y] = (t_coord *)ft_memalloc(sizeof(t_coord) * (data->column + 1));
	arr[data->column] = NULL;
	x = -1;
	while (coord[++x])
	{
		arr[y][x].x = x * SIZE;
		arr[y][x].y = y * SIZE;
		arr[y][x].z = ft_atoi(coord[x]) * SIZE;
	}
	return (arr);
}

t_coord	**read_coordinate(int fd, char *av, t_coord **arr, t_mlx *data)
{
	int		i;
	char	*line;
	char	**coord;

	data->row = 0;
	data->column = 0;
	while (get_next_line(fd, &line) > 0)
		data->row++;
	ft_memdel((void **)&line);
	arr = (t_coord **)ft_memalloc(sizeof(t_coord *) * (data->row + 1));
	arr[data->row] = NULL;
	close(fd);
	if ((fd = open(av, O_RDONLY)) == -1)
		exit(ft_printf("No file %s\n", av[1]));
	while (get_next_line(fd, &line) > 0)
	{
		coord = ft_strsplit(line, 32);
		i = 0;
		while (coord[i])
			i++;
		parse_coordinate(i, data, coord, arr);
		ft_memdel((void **)&line);
		ft_memdel((void **)coord);
	}
	return (arr);
}
