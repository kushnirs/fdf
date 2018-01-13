/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 21:58:17 by sergee            #+#    #+#             */
/*   Updated: 2018/01/13 11:08:19 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					close_window(t_mlx *data)
{
	data = NULL;
	exit(0);
	return (0);
}

int					mouse_action(int button, int x, int y, t_mlx *data)
{
	x = 0;
	y = 0;
	button == M_UP ? data->size += data->size / 4 : 0;
	button == M_DOWN ? data->size -= data->size / 4 : 0;
	ft_draw_polygon(data);
	return (0);
}

int					key_action(int key, t_mlx *data)
{
	key == ESC ? exit(0) : 0;
	key == UP ? data->move_y += 50 : 0;
	key == DOWN ? data->move_y += -50 : 0;
	key == RIGHT ? data->move_x += -50 : 0;
	key == LEFT ? data->move_x += 50 : 0;
	key == B_A ? data->rot.ry -= 5 : 0;
	key == B_W ? data->rot.rx -= 5 : 0;
	key == B_Q ? data->rot.rz -= 5 : 0;
	key == B_D ? data->rot.ry += 5 : 0;
	key == B_S ? data->rot.rx += 5 : 0;
	key == B_E ? data->rot.rz += 5 : 0;
	key == B_PLUS ? data->size += data->size / 10 : 0;
	key == B_MIN ? data->size -= data->size / 10 : 0;
	ft_draw_polygon(data);
	return (0);
}

unsigned int		parse_color(int c1, int c2, double t)
{
	unsigned char dr;
	unsigned char dg;
	unsigned char db;

	dr = (1 - t) * (double)(c1 / 0x10000 % 256) +
		t * (double)(c2 / 0x10000 % 256);
	dg = (1 - t) * (double)(c1 / 0x100 % 256) + t * (double)(c2 / 0x100 % 256);
	db = (1 - t) * (double)(c1 % 256) + t * (double)(c2 % 256);
	return (dr * 0x10000 + dg * 0x100 + db);
}

t_coord				ft_conversion_xyz(t_mlx *data, t_coord rot)
{
	t_coord	p[3];
	double	func[6];

	rot.x = rot.x * data->size + data->start.x;
	rot.y = rot.y * data->size + data->start.y;
	rot.z = rot.z * data->size / 2;
	func[0] = cos(PI * data->rot.rx / 180);
	func[1] = sin(PI * data->rot.rx / 180);
	func[2] = cos(PI * data->rot.ry / 180);
	func[3] = sin(PI * data->rot.ry / 180);
	func[4] = cos(PI * data->rot.rz / 180);
	func[5] = sin(PI * data->rot.rz / 180);
	p[0].x = rot.x;
	p[0].y = rot.y * func[0] + rot.z * func[1];
	p[0].z = rot.z * func[0] - rot.y * func[1];
	p[1].x = p[0].x * func[2] + p[0].z * func[3];
	p[1].y = p[0].y;
	p[1].z = p[0].z * func[2] - p[0].x * func[3];
	p[2].x = WIDTH / 2 + p[1].x * func[4] - p[1].y * func[5];
	p[2].y = HIGH / 2 + p[1].x * func[5] + p[1].y * func[4];
	p[2].z = p[1].z;
	p[2].color = rot.color;
	return (p[2]);
}
