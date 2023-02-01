/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:52:37 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/31 22:43:02 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_player_mouse(t_player *p, char move)
{
	double	old_dir_x;
	double	old_plane_x;
	double	speed;

	old_dir_x = p->pdx;
	old_plane_x = p->plane_x;
	speed = SPEED / 7;
	if (move == 'l')
	{
		p->pdx = p->pdx * cos(speed) - p->pdy * sin(speed);
		p->pdy = old_dir_x * sin(speed) + p->pdy * cos(speed);
		p->plane_x = p->plane_x * cos(speed) - p->plane_y * sin(speed);
		p->plane_y = old_plane_x * sin(speed) + p->plane_y * cos(speed);
	}
	if (move == 'r')
	{
		p->pdx = p->pdx * cos(-speed) - p->pdy * sin(-speed);
		p->pdy = old_dir_x * sin(-speed) + p->pdy * cos(-speed);
		p->plane_x = p->plane_x * cos(-speed) - p->plane_y * sin(-speed);
		p->plane_y = old_plane_x * sin(-speed) + p->plane_y * cos(-speed);
	}
}

int	mouse(int x, int y, t_data *data)
{
	(void)y;
	if (x > WIDTH / 2)
		rotate_player_mouse(&data->player, 'r');
	else if (x < WIDTH / 2)
		rotate_player_mouse(&data->player, 'l');
	else
		return (0);
	mlx_mouse_move(data->mlx, data->win, WIDTH / 2, HEIGHT / 2);
	display_map(data, &data->pixel, &data->info);
	return (0);
}

void	ft_mouse(t_data *data)
{
	mlx_mouse_hide(data->mlx, data->win);
	mlx_hook(data->win, 6, 1L << 6, mouse, data);
}
