/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:16:19 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/16 13:15:19 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	key_hook(int keycode, t_data *l)
{
	(void)l;
	if (keycode == XK_Escape)
		close_win(l);
/*	if (keycode == XK_w)
		move_heros(l, 'w');
	if (keycode == XK_a)
		move_heros(l, 'a');
	if (keycode == XK_s)
		move_heros(l, 's');
	if (keycode == XK_d)
		move_heros(l, 'd');*/
	return (0);
}

void	play(t_data *l)
{
	mlx_key_hook(l->win, key_hook, l);
	mlx_hook(l->win, 17, 0, close_win, l);
	mlx_loop(l->mlx);
}

void	init_vars(t_data *l)
{
	l->mlx = mlx_init();
	//init_sprite(l);
	l->win = mlx_new_window(l->mlx, 800, 600, "cub3D");
}

int main()
{
	t_data	l;

	init_vars(&l);
	play(&l);
    return (0);
}
