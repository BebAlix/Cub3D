/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:34:42 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/19 12:22:31 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_player(t_data *data, char move)
{
	if (move == 'w')
		data->player.x -= 1;
	if (move == 'a')
		data->player.y -= 1;
	if (move == 's')
		data->player.x += 1;
	if (move == 'd')
		data->player.y += 1;
	set_background(data->pixel);
	print_map(data->pixel, &data->parse);
	print_player(data->pixel, data->player.x, data->player.y, RED);
	mlx_put_image_to_window(data->mlx, data->win, data->pixel.img, 0, 0);
}

static int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_win(data);
	if (keycode == XK_w)
		move_player(data, 'w');
	if (keycode == XK_a)
		move_player(data, 'a');
	if (keycode == XK_s)
		move_player(data, 's');
	if (keycode == XK_d)
		move_player(data, 'd');
	return (0);
}

void	play(t_data *data)
{
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 17, 0, close_win, data);
	mlx_loop(data->mlx);
}
