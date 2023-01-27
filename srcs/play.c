/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:34:42 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/27 18:23:17 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_player(t_data *data, char move)
{

	if (move == 'w')
	{
		if(data->parse.map[(int)(data->player.y - 1)][(int)(data->player.x - 1 + data->player.pdx * 0.1)] != '1')
			data->player.x += data->player.pdx * 0.1;
		if(data->parse.map[(int)(data->player.y - 1 + data->player.pdy * 0.1)][(int)(data->player.x - 1)] != '1')
			data->player.y += data->player.pdy * 0.1;
	}
	if (move == 's')
	{
		if(data->parse.map[(int)(data->player.y + 1)][(int)(data->player.x + 1 - data->player.pdx * 0.1)] != '1')
			data->player.x -= data->player.pdx * 0.1;
		if(data->parse.map[(int)(data->player.y + 1 - data->player.pdy * 0.1)][(int)(data->player.x + 1)] != '1')
			data->player.y -= data->player.pdy * 0.1;
	}
	if (move == 'd')
	{
		if(data->parse.map[(int)(data->player.y + 0.2)][(int)(data->player.x + 0.2 + data->player.planeX * 0.1)] != '1')
			data->player.x += data->player.planeX * 0.1;
		if(data->parse.map[(int)(data->player.y + 0.2 + data->player.planeY * 0.1)][(int)(data->player.x + 0.2)] != '1')
			data->player.y += data->player.planeY * 0.1;
	}
	if (move == 'a')
	{
		if(data->parse.map[(int)(data->player.y - 0.2)][(int)(data->player.x - 0.2 - data->player.planeX * 0.1)] != '1')
			data->player.x -= data->player.planeX * 0.1;
		if(data->parse.map[(int)(data->player.y - 0.2 - data->player.planeY * 0.1)][(int)(data->player.x - 0.2)] != '1')
			data->player.y -= data->player.planeY * 0.1;
	}
}

void	rotate_player(t_player *player, char move)
{
	
	if (move == 'l')
	{
		double oldDirX = player->pdx;
    	player->pdx = player->pdx* cos(0.1) - player->pdy * sin(0.1);
    	player->pdy = oldDirX * sin(0.1) + player->pdy * cos(0.1);
    	double oldPlaneX = player->planeX;
    	player->planeX = player->planeX * cos(0.1) - player->planeY * sin(0.1);
    	player->planeY = oldPlaneX * sin(0.1) + player->planeY * cos(0.1);
	}
	if (move == 'r')
	{
		double oldDirX = player->pdx;
    	player->pdx = player->pdx* cos(-0.1) - player->pdy * sin(-0.1);
    	player->pdy = oldDirX * sin(-0.1) + player->pdy * cos(-0.1);
    	double oldPlaneX = player->planeX;
    	player->planeX = player->planeX * cos(-0.1) - player->planeY * sin(-0.1);
    	player->planeY = oldPlaneX * sin(-0.1) + player->planeY * cos(-0.1);
	}
	printf("pdx = %f\n", player->pdx);
	printf("pdy = %f\n", player->pdy);
//	printf("pa = %f\n", data->player.pa);
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
