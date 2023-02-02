/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:06:19 by equesnel          #+#    #+#             */
/*   Updated: 2023/02/02 17:06:21 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_player_n_s(t_player *p, char **map, char move)
{
	if (move == 'w')
	{
		if (map[(int)(p->y)][(int)(p->x + p->pdx * SPEED)] != '1')
			p->x += p->pdx * SPEED;
		if (map[(int)(p->y + p->pdy * SPEED)][(int)(p->x)] != '1')
			p->y += p->pdy * SPEED;
	}
	if (move == 's')
	{
		if (map[(int)(p->y)][(int)(p->x - p->pdx * SPEED)] != '1')
			p->x -= p->pdx * SPEED;
		if (map[(int)(p->y - p->pdy * SPEED)][(int)(p->x)] != '1')
			p->y -= p->pdy * SPEED;
	}
}

void	move_player_e_w(t_player *p, char **map, char move)
{
	if (move == 'd')
	{
		if (map[(int)(p->y)][(int)(p->x + p->plane_x * SPEED)] != '1')
			p->x += p->plane_x * SPEED;
		if (map[(int)(p->y + p->plane_y * SPEED)][(int)(p->x)] != '1')
			p->y += p->plane_y * SPEED;
	}
	if (move == 'a')
	{
		if (map[(int)(p->y)][(int)(p->x - p->plane_x * SPEED)] != '1')
			p->x -= p->plane_x * SPEED;
		if (map[(int)(p->y - p->plane_y * SPEED)][(int)(p->x)] != '1')
			p->y -= p->plane_y * SPEED;
	}
}

void	rotate_player(t_player *p, char move)
{
	double	old_dir_x;
	double	old_plane_x;
	double	speed;

	speed = SPEED / 2;
	old_dir_x = p->pdx;
	old_plane_x = p->plane_x;
	if (move == 'r')
	{
		p->pdx = p->pdx * cos(speed) - p->pdy * sin(speed);
		p->pdy = old_dir_x * sin(speed) + p->pdy * cos(speed);
		p->plane_x = p->plane_x * cos(speed) - p->plane_y * sin(speed);
		p->plane_y = old_plane_x * sin(speed) + p->plane_y * cos(speed);
	}
	if (move == 'l')
	{
		p->pdx = p->pdx * cos(-speed) - p->pdy * sin(-speed);
		p->pdy = old_dir_x * sin(-speed) + p->pdy * cos(-speed);
		p->plane_x = p->plane_x * cos(-speed) - p->plane_y * sin(-speed);
		p->plane_y = old_plane_x * sin(-speed) + p->plane_y * cos(-speed);
	}
}

static int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_win(data);
	else if (keycode == XK_w)
		move_player_n_s(&data->player, data->info.map, 'w');
	else if (keycode == XK_s)
		move_player_n_s(&data->player, data->info.map, 's');
	else if (keycode == XK_a)
		move_player_e_w(&data->player, data->info.map, 'a');
	else if (keycode == XK_d)
		move_player_e_w(&data->player, data->info.map, 'd');
	else if (keycode == XK_Right)
		rotate_player(&data->player, 'r');
	else if (keycode == XK_Left)
		rotate_player(&data->player, 'l');
	else
		return (0);
	display_map(data, &data->pixel, &data->info);
	return (0);
}

void	play(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->win, 17, 0, close_win, data);
	//ft_mouse(data); // bonus
	mlx_loop(data->mlx);
}
