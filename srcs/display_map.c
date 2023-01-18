/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:26:08 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/18 23:24:57 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_pixel *pixel, int x, int y, int color)
{
	char	*dst;

	dst = pixel->addr + (y * pixel->line_length + x
			* (pixel->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	set_background(t_pixel pixel)
{
	int	x;
	int	y;
	int	middle;

	x = 0;
	y = 0;
	middle = height / 2;
	while (y < middle)
	{
		my_mlx_pixel_put(&pixel, x, y, blue);
		if (x == width)
		{
			x = 0;
			y++;
		}
		x++;
	}
	while (y < height)
	{
		my_mlx_pixel_put(&pixel, x, y, brown);
		if (x == width)
		{
			x = 0;
			y++;
		}
		x++;
	}
}

void	create_square(t_pixel pixel, int x, int y, int color)
{
	int	x_max;
	int	y_max;

	x_max = x + 32;
	y_max = y + 32;
	x += 1;
	while (x < x_max)
	{
		while (y < y_max)
		{
			my_mlx_pixel_put(&pixel, y, x, color);
			y++;
		}
		y -= 31;
		x++;
	}
}

void	print_map(t_pixel pixel, t_parse *parse)
{
	int	x;
	int	y;

	x = 0;
	while (parse->map[x])
	{
		y = 0;
		while (parse->map[x][y])
		{
			if (parse->map[x][y] != ' ')
			{
				if (parse->map[x][y] == '0')
					create_square(pixel, x * 32, y * 32, white);
				if (parse->map[x][y] == '1')
					create_square(pixel, x * 32, y * 32, grey);
				if (parse->map[x][y] == 'N' || parse->map[x][y] == 'W' || parse->map[x][y] == 'E' || parse->map[x][y] == 'S')
					create_square(pixel, x * 32, y * 32, white);
			}
			y++;
		}
		x++;
	}
}

void	print_player(t_pixel pixel, t_player *player, int color)
{
	my_mlx_pixel_put(&pixel, player->y * 32, player->x * 32, color);
}

void	display_map(t_data *data, t_pixel pixel)
{
	set_background(pixel);
	print_map(pixel, &data->parse);
	print_player(pixel, &data->player, red);
}
