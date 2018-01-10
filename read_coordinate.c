/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_coordinate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 15:55:45 by skushnir          #+#    #+#             */
/*   Updated: 2018/01/10 21:22:14 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	parse_coordinate(int y, t_mlx *data, char **coord)
{
	int	x;

	if (!data->column)
	{
		data->column = y;
		data->start.x = y / 2 * (-SIZE);
		data->start.y = data->row / 2 * (-SIZE);
	}
	data->column != y ?
		exit(write(1, "Found wrong line length. Exiting.\n", 34)) : 0;
	y = 0;
	while (data->arr[y])
		y++;
	data->arr[y] = (t_coord *)ft_memalloc(sizeof(t_coord) * (data->column + 1));
	data->arr[data->column] = NULL;
	x = -1;
	while (coord[++x])
	{
		data->arr[y][x].x = x * SIZE + data->start.x;
		data->arr[y][x].y = y * SIZE + data->start.y;
		data->arr[y][x].z = ft_atoi(coord[x]) * SIZE;
		data->arr[y][x].color = (ft_strchr(coord[x], ',') ?
		ft_hex_to_dec(ft_strchr(coord[x], ',') + 1) : 0xFFFFFF);
	}
}

void	read_coordinate(int fd, char *av, t_mlx *data)
{
	int		i;
	char	*line;
	char	**coord;

	data->row = 0;
	data->column = 0;
	while (get_next_line(fd, &line) > 0)
	{
		ft_memdel((void **)&line);
		data->row++;
	}
	close(fd);
	data->arr = (t_coord **)ft_memalloc(sizeof(t_coord *) * (data->row + 1));
	data->arr[data->row] = NULL;
	if ((fd = open(av, O_RDONLY)) == -1)
		exit(ft_printf("No file %s\n", av));
	while (get_next_line(fd, &line) > 0)
	{
		coord = ft_strsplit(line, 32);
		i = 0;
		while (coord[i])
			i++;
		parse_coordinate(i, data, coord);
		ft_memdel((void **)&line);
		ft_memdel((void **)&coord);
	}
}
