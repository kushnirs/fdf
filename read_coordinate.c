/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_coordinate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 15:55:45 by skushnir          #+#    #+#             */
/*   Updated: 2018/01/04 20:24:56 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	parse_coordinate(int i, t_mlx *data, char **coord)
{
	t_coord	arr[data->row * i];

	!data->column ? data->column = i : 0;
	data->column != i ?	exit(write(1, "Found wrong line length. Exiting.\n", 34)) : 0;


}

int	read_coordinate(int fd, char *av)
{
	int		i;
	char	*line;
	char	**coord;
	t_mlx	data;

	data.row = 0;
	data.column = 0;
	while (get_next_line(fd, &line) > 0)
		data.row++;
	close(fd);
	if ((fd = open(av, O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &line) > 0)
	{
		coord = ft_strsplit(line, 32);
		i = 0;
		while (coord[i])
			i++;
		parse_coordinate(i, &data, coord);
	}
	return (0);
}