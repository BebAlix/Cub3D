/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:34:42 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/20 15:13:31 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_player(t_data *data, char move)
{
	if (move == 'w')
	{
		data->player.x -= data->player.pdx;
		data->player.y -= data->player.pdy;
	}
	if (move == 's')
	{
		data->player.x += data->player.pdx;
		data->player.y += data->player.pdy;
	}
	if (move == 'a')
	{
		data->player.x += data->player.pdx;
		data->player.y -= data->player.pdy;
	}
	if (move == 'd')
	{
		data->player.x -= data->player.pdx;
		data->player.y += data->player.pdy;
	}
	set_background(data->pixel);
	print_map(data->pixel, &data->parse);
	print_player(data->pixel, data->player.x * 32.0, data->player.y * 32.0, RED);
	mlx_put_image_to_window(data->mlx, data->win, data->pixel.img, 0, 0);
}

void	rotate_player(t_data *data, char move)
{
	
	if (move == 'l')
	{
		data->player.pa -= 0.1;
		if (data->player.pa < 0.0)
			data->player.pa += 2.0 * M_PI;
		data->player.pdx = cos(data->player.pa) * 0.1;
		data->player.pdy = sin(data->player.pa) * 0.1;
	}
	if (move == 'r')
	{
		data->player.pa += 0.1;
		if (data->player.pa > 2.0 * M_PI)
			data->player.pa -= 2.0 * M_PI;
		data->player.pdx = cos(data->player.pa) * 0.1;
		data->player.pdy = sin(data->player.pa) * 0.1;
	}
	printf("pdx = %f\n", data->player.pdx);
	printf("pdy = %f\n", data->player.pdy);
	printf("pa = %f\n", data->player.pa);
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
		rotate_player(data, 'r');
	if (keycode == XK_Left)
		rotate_player(data, 'l');
	return (0);
}

void	play(t_data *data)
{
	printf("pdx = %f\n", data->player.pdx);
	printf("pdy = %f\n", data->player.pdy);
	printf("pa = %f\n", data->player.pa);
	mlx_hook(data->win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->win, 17, 0, close_win, data);
	mlx_loop(data->mlx);
}
