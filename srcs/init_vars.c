/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:26:39 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/28 14:29:49 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_player_position(t_player *player, char **map, char orientation)
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
	player->pdx = -1;
	player->pdy = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
/*	
	printf("orientation = %c\n", orientation);
	if (orientation == 'S')
		player->pa = M_PI / 2.0;
	if (orientation == 'N')
		player->pa = (M_PI * 3.0) / 2.0;
	if (orientation == 'E')
		player->pa = M_PI * 2.0;
	if (orientation == 'W')
		player->pa = M_PI;*/
	//player->pdx = cos(player->pa) * 0.1;
	//player->pdy = sin(player->pa) * 0.1;
	//player->camera = 0.33;
}

void	init_vars(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return ; // free and exit
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3D");
	data->pixel.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->pixel.addr = mlx_get_data_addr(data->pixel.img, &data->pixel.bits_per_pixel,
			&data->pixel.line_length, &data->pixel.endian);
	init_player_position(&data->player, data->parse.map, data->parse.player_position);
}
