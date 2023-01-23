/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:26:08 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/20 15:20:51 by equesnel         ###   ########.fr       */
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
	int	y;
	int	x;
	int	middle;

	x = 0.0;
	y = 0.0;
	middle = HEIGHT / 2.0;
	while (y < middle)
	{
		my_mlx_pixel_put(&pixel, x, y, BLUE);
		if (x == WIDTH)
		{
			x = 0.0;
			y++;
		}
		x++;
	}
	while (y < HEIGHT)
	{
		my_mlx_pixel_put(&pixel, x, y, BROWN);
		if (x == WIDTH)
		{
			x = 0.0;
			y++;
		}
		x++;
	}
}

void	create_square(t_pixel pixel, int x, int y, int color)
{
	int	y_max;
	int	x_max;

	x_max = x + 32.0;
	y_max = y + 32.0;
	y += 1.0;
	while (y < y_max)
	{
		while (x < x_max)
		{
			my_mlx_pixel_put(&pixel, x, y, color);
			x++;
		}
		x -= 31.0;
		y++;
	}
}

void	print_map(t_pixel pixel, t_parse *parse)
{
	int	y;
	int	x;

	y = 0;
	while (parse->map[y])
	{
		x = 0;
		while (parse->map[y][x])
		{
			if (parse->map[y][x] != ' ')
			{
				if (parse->map[y][x] == '0')
					create_square(pixel, x * 32.0, y * 32.0, WHITE);
				if (parse->map[y][x] == '1')
					create_square(pixel, x * 32.0, y * 32.0, GREY);
				if (parse->map[y][x] == 'N' || parse->map[y][x] == 'W' || parse->map[y][x] == 'E' || parse->map[y][x] == 'S')
					create_square(pixel, x * 32.0, y * 32.0, WHITE);
			}
			x++;
		}
		y++;
	}
}

void	print_zigouigoui(t_pixel pixel, t_player *player, double x, double y, int color)
{
	(void) player;
	int	i;
	
	i = 0;
	while (i < 100)
	{
		my_mlx_pixel_put(&pixel, x + (player->pdx * i), y + (player->pdy * i), color);
		i++;
	}

}

void	print_player(t_pixel pixel, t_player *player, double x, double y, int color)
{
	int	y_max;
	int	x_max;

	y_max = y + 4.0;
	x_max = x + 4.0;
	x -= 4.0;
	y -= 4.0;
	while (y < y_max)
	{
		while (x < x_max)
		{
			my_mlx_pixel_put(&pixel, x, y, color);
			x++;
		}
		x -= 8.0;
		y++;
	}
	//if (player->pa < 0.0)
	print_zigouigoui(pixel, player, x + 4.0 , y - 4.0, RED);
//	if (player->pa > 2.0 * M_PI)
//		print_zigouigoui(pixel, player, x , y + 4.0 , RED);
}

void	display_map(t_data *data, t_pixel pixel)
{
	set_background(pixel);
	print_map(pixel, &data->parse);
	print_player(pixel, &data->player, data->player.x * 32.0, data->player.y * 32.0, RED);
	mlx_put_image_to_window(data->mlx, data->win, data->pixel.img, 0, 0);
}
