/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:02:09 by equesnel          #+#    #+#             */
/*   Updated: 2023/02/02 17:46:36 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_orientation_n_s(t_player *player, char orientation)
{
	if (orientation == 'N')
	{
		player->pdx = 0;
		player->pdy = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	if (orientation == 'S')
	{
		player->pdx = 0;
		player->pdy = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
}

static void	init_orientation_e_w(t_player *player, char orientation)
{
	if (orientation == 'E')
	{
		player->pdx = 1;
		player->pdy = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	if (orientation == 'W')
	{
		player->pdx = -1;
		player->pdy = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
}

void	init_player(t_player *player, char **map, char orientation)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == orientation)
			{
				player->x = x + 0.5;
				player->y = y + 0.5;
			}
			x++;
		}
		y++;
	}
	init_orientation_n_s(player, orientation);
	init_orientation_e_w(player, orientation);
}
