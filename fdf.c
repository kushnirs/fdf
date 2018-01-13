/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergee <sergee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:13:45 by skushnir          #+#    #+#             */
/*   Updated: 2018/01/13 03:21:37 by sergee           ###   ########.fr       */
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

int	main(int ar, char **av)
{
	int		fd;
	t_mlx	data;

	ar > 3 || ar == 1 ?
	exit(write(1, "Usage : ./fdf <filename>[ case_size z_size ]\n", 46)) : 0;
	if ((fd = open(av[1], O_RDONLY)) == -1)
		exit(ft_printf("No file %s\n", av[1]));
	data = (t_mlx){NULL, NULL, NULL, 0, 0, 0, NULL, 10, 0, 0, 0, 0,
			{-60, 50, 0}, {0, 0, 0, 0}, NULL, 0};
	ar == 3 && !ft_strcmp(av[2], "-f") ? data.p = 1 : 0;
	read_coordinate(fd, av[1], &data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HIGH, "fdf");
	data.image = mlx_new_image(data.mlx, WIDTH, HIGH);
	data.data_adr =
	(t_ui *)mlx_get_data_addr(data.image, &data.bpp, &data.sl, &data.endian);
	ft_draw_polygon(&data);
	mlx_mouse_hook(data.win, &mouse_action, &data);
	mlx_key_hook(data.win, &key_action, &data);
	mlx_hook(data.win, 17, 0, &close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}

