/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:34:42 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/19 16:06:43 by equesnel         ###   ########.fr       */
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

void	rotate_player(t_data *data, char move)
{
	
	if (move == 'a')
	{
      double oldDirX;

	  oldDirX = data->player.pdx;
      data->player.pdx = data->player.pdx * cos(5) - data->player.pdy * sin(5);
      data->player.pdy = oldDirX * sin(5) + data->player.pdy * cos(5);
	}
	printf("pdx = %f\n", data->player.pdx);
	printf("pdy = %f\n", data->player.pdy);
	/*if (move == 'd')
	{
		data->player.pa += 0.1;
		if (data->player.pa > 2 * M_PI)
			data->player.pa -= 2 * M_PI;
		data->player.pdx = cos(data->player.pa) * 5;
		data->player.pdy = sin(data->player.pa) * 5;
	}*/
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
		rotate_player(data, 'a');
	if (keycode == XK_d)
		rotate_player(data, 'd');
	return (0);
}

void	play(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->win, 17, 0, close_win, data);
	mlx_loop(data->mlx);
}
