/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:34:42 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/28 14:05:23 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_player(t_data *data, char move)
{
	if (move == 'w')
	{
		if (data->parse.map[(int)(data->player.y)][(int)(data->player.x + data->player.pdx * 0.1)] != '1')
			data->player.x += data->player.pdx * 0.1;
		if (data->parse.map[(int)(data->player.y + data->player.pdy * 0.1)][(int)(data->player.x)] != '1')
			data->player.y += data->player.pdy * 0.1;
	}
	if (move == 's')
	{
		if (data->parse.map[(int)(data->player.y)][(int)(data->player.x - data->player.pdx * 0.1)] != '1')
			data->player.x -= data->player.pdx * 0.1;
		if (data->parse.map[(int)(data->player.y - data->player.pdy * 0.1)][(int)(data->player.x)] != '1')
			data->player.y -= data->player.pdy * 0.1;
	}
	if (move == 'd')
	{
		if (data->parse.map[(int)(data->player.y)][(int)(data->player.x + data->player.plane_x * 0.1)] != '1')
			data->player.x += data->player.plane_x * 0.1;
		if (data->parse.map[(int)(data->player.y + data->player.plane_y * 0.1)][(int)(data->player.x)] != '1')
			data->player.y += data->player.plane_y * 0.1;
	}
	if (move == 'a')
	{
		if (data->parse.map[(int)(data->player.y)][(int)(data->player.x - data->player.plane_x * 0.1)] != '1')
			data->player.x -= data->player.plane_x * 0.1;
		if (data->parse.map[(int)(data->player.y - data->player.plane_y * 0.1)][(int)(data->player.x)] != '1')
			data->player.y -= data->player.plane_y * 0.1;
	}
}

void	rotate_player(t_player *player, char move)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->pdx;
	old_plane_x = player->plane_x;
	if (move == 'l')
	{
		player->pdx = player->pdx * cos(0.1) - player->pdy * sin(0.1);
		player->pdy = old_dir_x * sin(0.1) + player->pdy * cos(0.1);
		player->plane_x = player->plane_x * cos(0.1) - player->plane_y * sin(0.1);
		player->plane_y = old_plane_x * sin(0.1) + player->plane_y * cos(0.1);
	}
	if (move == 'r')
	{
		player->pdx = player->pdx * cos(-0.1) - player->pdy * sin(-0.1);
		player->pdy = old_dir_x * sin(-0.1) + player->pdy * cos(-0.1);
		player->plane_x = player->plane_x * cos(-0.1) - player->plane_y * sin(-0.1);
		player->plane_y = old_plane_x * sin(-0.1) + player->plane_y * cos(-0.1);
	}
}

static int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_win(data);
	if (keycode == XK_w)
		move_player(data, 'w');
	if (keycode == XK_s)
		move_player(data, 's');
	if (keycode == XK_a)
		move_player(data, 'a');
	if (keycode == XK_d)
		move_player(data, 'd');
	if (keycode == XK_Right)
		rotate_player(&data->player, 'r');
	if (keycode == XK_Left)
		rotate_player(&data->player, 'l');
	display_map(data, &data->pixel, data->parse.map);
	return (0);
}

void	play(t_data *data)
{
	printf("pdx = %f\n", data->player.pdx);
	printf("pdy = %f\n", data->player.pdy);
	//printf("pa = %f\n", data->player.pa);
	mlx_hook(data->win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->win, 17, 0, close_win, data);
	mlx_loop(data->mlx);
}
