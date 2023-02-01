/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_print_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:53:01 by equesnel          #+#    #+#             */
/*   Updated: 2023/02/01 20:57:25 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	print_square(t_data *data, int x, int y, int color)
{
	int	y_max;
	int	x_max;

	y *= PADDING;
	x *= PADDING;
	y_max = y + PADDING;
	x_max = x + PADDING;
	while (y < y_max)
	{
		while (x < x_max)
		{
			my_mlx_pixel_put(&data->pixel, x, y, color);
			x++;
		}
		x -= PADDING;
		y++;
	}
}

void	print_map(t_data *data, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
			{
				print_square(data, x, y, 0x000000);
			}
			if (map[y][x] == '0'
			|| map[y][x] == 'N'
			|| map[y][x] == 'W'
			|| map[y][x] == 'E'
			|| map[y][x] == 'S')
			{
				print_square(data, x, y, 0xffffff);
			}
			x++;
		}
		y++;
	}
}
