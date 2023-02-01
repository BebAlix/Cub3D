/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:26:08 by equesnel          #+#    #+#             */
/*   Updated: 2023/02/01 16:24:46 by equesnel         ###   ########.fr       */
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

static void	draw_ceil(t_pixel *pixel, int ceil)
{
	int	y;
	int	x;
	int	middle;

	x = 0;
	y = 0;
	middle = HEIGHT / 2;
	while (y < middle)
	{
		my_mlx_pixel_put(pixel, x, y, ceil);
		if (x == WIDTH)
		{
			x = 0.0;
			y++;
		}
		x++;
	}
}

static void	draw_floor(t_pixel *pixel, int floor)
{
	int	y;
	int	x;

	x = 0;
	y = HEIGHT / 2;
	while (y < HEIGHT)
	{
		my_mlx_pixel_put(pixel, x, y, floor);
		if (x == WIDTH)
		{
			x = 0;
			y++;
		}
		x++;
	}
}

void	display_map(t_data *data, t_pixel *pixel, t_info *info)
{
	draw_ceil(pixel, data->info.ceil);
	draw_floor(pixel, data->info.floor);
	raycasting(&data->ray, pixel, &data->player, info);
	mlx_put_image_to_window(data->mlx, data->win, data->pixel.img, 0, 0);
}
