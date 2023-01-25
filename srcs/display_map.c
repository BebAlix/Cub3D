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
	int	i;
	
	i = 0;
	while (i < 150)
	{
		my_mlx_pixel_put(&pixel, x + (player->pdx * i), y + (player->pdy * i), color);
		i++;
	}
}


void	print_player(t_pixel pixel, t_player *player, double x, double y, int color)
{
	int	y_max;
	int	x_max;
	(void) player;
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
	print_zigouigoui(pixel, player, x + 4.0 , y - 4.0 , RED);
}

void	draw_line(t_pixel pixel, int x, int y, int endx, int endy, int color)
{
	(void) pixel;
	double deltaX = endx  - x;
	double deltaY = endy  - y;
	double pixelX = x;
	double pixelY = y;
	int	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));

	printf("deltaX = %f\n", deltaX);
	printf("deltaY = %f\n", deltaY);
	
	printf("pixel = %d\n", pixels);
	deltaX /= pixels;
	deltaY /= pixels;
	while (pixels)
	{
		printf("pixel = %d\n", pixels);
		my_mlx_pixel_put(&pixel, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		pixels--;
	}
}

void	ray_casting(t_pixel pixel, t_player *player, char **map)
{
	double cameraX;
	int	x = 0;
	int	mapX = player->x;
	int	mapY = player->y;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int	stepX;
	int	stepY;
	int	hit = 0;
	int	side;
	//int	lineHeight = ()
	(void) pixel;
	while (x < WIDTH)
	{
		cameraX = 2 * x / (double)WIDTH - 1;
		player->rayDirX = player->pdx + player->planeX * cameraX;
		player->rayDirY = player->pdy + player->planeY * cameraX;
		x++;
		if (player->rayDirX)
			deltaDistX = 1e30;
		else
			deltaDistX = abs(1 /  (int)player->rayDirX);
		if (player->rayDirY)
			deltaDistY = 1e30;
		else
			deltaDistY = abs(1 /  (int)player->rayDirY);
			
		if (player->rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (player->x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - player->x) * deltaDistX;
		}
		if (player->rayDirY > 0)
		{
			stepY = -1;
			sideDistY = (player->y - mapY) * deltaDistY;
		}
		else
		{
			stepY = -1;
			sideDistY = (mapY + 1.0 - player->y) * deltaDistX;	
		}
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (map[mapY][mapX] == '1')
				hit = 1;
		}
	if (side == 0)
		perpWallDist = (sideDistX - deltaDistX);
	else
		perpWallDist = (sideDistY - deltaDistY);
	//Calculate height of line to draw on screen
	int lineHeight = (int)(HEIGHT / perpWallDist);
      
	//calculate lowest and highest pixel to fill in current stripe
	int drawStart = -lineHeight / 2 + HEIGHT / 2;
	if(drawStart < 0)
		drawStart = 0;
	int drawEnd = lineHeight / 2 + HEIGHT / 2;
	if(drawEnd >= HEIGHT) 
		drawEnd = HEIGHT - 1;
	my_mlx_pixel_put(&pixel, drawEnd, drawStart, 997485);
	my_mlx_pixel_put(&pixel, drawEnd + 1, drawStart, 997485);
}
}

void	display_map(t_data *data, t_pixel pixel, char **map)
{
	set_background(pixel);
	print_map(pixel, &data->parse);
	print_player(pixel, &data->player, data->player.x * 32.0, data->player.y * 32.0, RED);
	ray_casting(data->pixel, &data->player, map);
	mlx_put_image_to_window(data->mlx, data->win, data->pixel.img, 0, 0);
}
