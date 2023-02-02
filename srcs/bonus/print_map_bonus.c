/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:53:01 by equesnel          #+#    #+#             */
/*   Updated: 2023/02/02 18:24:18 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

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

static void	print_player(t_data *data, double x, double y, t_map m)
{
	x *= PADDING;
	y *= PADDING;
	my_mlx_pixel_put(&data->pixel, x, y, 0x000000);
	my_mlx_pixel_put(&data->pixel, x - 1, y - 1, 0x000000);
	my_mlx_pixel_put(&data->pixel, x - 1, y + 1, 0x000000);
	my_mlx_pixel_put(&data->pixel, x + 1, y - 1, 0x000000);
	my_mlx_pixel_put(&data->pixel, x + 1, y + 1, 0x000000);
	free_double_char(m.new_map);
}

void	print_map(t_data *data, t_map m, char **map)
{
	m.y = floor(data->player.y);
	m.x = floor(data->player.x);
	m.old_y = m.y;
	m.old_x = m.x;
	m.y_max = m.y + 6;
	m.x_max = m.x + 6;
	m.new_map = change_map(map);
	while (m.y < m.y_max)
	{
		while (m.x < m.x_max)
		{
			if (m.new_map[m.y][m.x] == '1')
				print_square(data, m.x - m.old_x, m.y - m.old_y, 0x000000);
			if (m.new_map[m.y][m.x] == '0'
			|| m.new_map[m.y][m.x] == 'N'
			|| m.new_map[m.y][m.x] == 'W'
			|| m.new_map[m.y][m.x] == 'E'
			|| m.new_map[m.y][m.x] == 'S')
				print_square(data, m.x - m.old_x, m.y - m.old_y, 0xffffff);
			m.x++;
		}
		m.x -= 6;
		m.y++;
	}
	print_player(data, 3.5, 3.5, m);
}
