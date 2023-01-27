/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:26:08 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/27 17:45:22 by equesnel         ###   ########.fr       */
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

void	draw_vertical_line(t_pixel *pixel, int x, int drawStart, int drawEnd, int color)
{
	int	i;
	
	i = drawStart;
	while (i < drawEnd)
	{
		my_mlx_pixel_put(pixel, x , i, color);
		i++;
	}
}


void	set_background(t_pixel *pixel)
{
	int	y;
	int	x;
	int	middle;

	x = 0.0;
	y = 0.0;
	middle = HEIGHT / 2.0;
	while (y < middle)
	{
		my_mlx_pixel_put(pixel, x, y, BLUE);
		if (x == WIDTH)
		{
			x = 0.0;
			y++;
		}
		x++;
	}
	while (y < HEIGHT)
	{
		my_mlx_pixel_put(pixel, x, y, BROWN);
		if (x == WIDTH)
		{
			x = 0.0;
			y++;
		}
		x++;
	}
}

void	raycasting(t_pixel *pixel, t_player *player, char **map)
{
	(void) pixel;
	(void) player;
	(void) map;
	
	int	x;
	int	mapX;
	int	mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int	stepX;
	int	stepY;
	int	hit;
	int	side;
	int	lineHeight;
	int	drawStart;
	int	drawEnd;
	
	x = 0;
	while (x < WIDTH)
	{
		player->cameraX = (2 * x) / (double) WIDTH - 1;
		player->rayDirX = player->pdx + player->planeX * player->cameraX;
		player->rayDirY = player->pdy + player->planeY * player->cameraX;
		
		
		// printf("player->rayDirX = %f\n", player->rayDirX);
		// printf("player->rayDirY = %f\n", player->rayDirY);
		// printf("player->cameraX = %f\n",player->cameraX);
		printf("player->pdx = %f\n",player->pdx);
		printf("player->pdy = %f\n",player->pdy);
		printf("player->x = %f\n",player->x);
		printf("player->y = %f\n",player->y);
		printf("player->planex = %f\n",player->planeX);
		printf("player->planey = %f\n",player->planeY);
		
		
		mapX = (int) player->x;
		mapY = (int) player->y;
		
		if (player->rayDirX == 0)
			deltaDistX = 1000;
		else if (player->rayDirX != 0)
			deltaDistX = fabs(1 / player->rayDirX);
		if (player->rayDirY == 0)
			deltaDistY = 1000;
		else if (player->rayDirY != 0)
			deltaDistY = fabs(1 / player->rayDirY);
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
		if (player->rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (player->y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - player->y) * deltaDistY;
		}
		hit = 0;
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
			if (side == 0)
				perpWallDist = (sideDistX - deltaDistX);
			else
				perpWallDist = (sideDistY - deltaDistY);
			if (map[mapY][mapX] == '1')
				hit = 1;
		}
		lineHeight = (int) (HEIGHT / perpWallDist);
		drawStart = -lineHeight / 2 + HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + HEIGHT / 2;
		if (drawEnd >= HEIGHT)
			drawEnd = HEIGHT - 1;
		draw_vertical_line(pixel, x, drawStart, drawEnd, RED);
		x++;
	}
}

void	display_map(t_data *data, t_pixel *pixel, char **map)
{
	(void) map;
	set_background(pixel);
	raycasting(pixel, &data->player, map);
	mlx_put_image_to_window(data->mlx, data->win, data->pixel.img, 0, 0);
}
