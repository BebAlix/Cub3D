/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:26:08 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/30 20:14:49 by equesnel         ###   ########.fr       */
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

void	draw_ceil(t_pixel *pixel, int ceil)
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

void	draw_floor(t_pixel *pixel, int floor)
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

void	draw_vertical_line(t_pixel *pixel, int x, int draw_start, int draw_end, int color)
{
	int	i;

	i = draw_start;
	while (i <= draw_end)
	{
		my_mlx_pixel_put(pixel, x, i, color);
		i++;
	}
}

void	raycasting(t_ray *ray, t_pixel *pixel, t_player *player, char **map)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		player->camera_x = (2 * x) / (double) WIDTH - 1;
		player->ray_dir_x = player->pdx + player->plane_x * player->camera_x;
		player->ray_dir_y = player->pdy + player->plane_y * player->camera_x;
		ray->map_x = (int) player->x;
		ray->map_y = (int) player->y;
		if (player->ray_dir_x == 0)
			ray->delta_dist_x = 1000;
		else if (player->ray_dir_x != 0)
			ray->delta_dist_x = fabs(1 / player->ray_dir_x);
		if (player->ray_dir_y == 0)
			ray->delta_dist_y = 1000;
		else if (player->ray_dir_y != 0)
			ray->delta_dist_y = fabs(1 / player->ray_dir_y);
		if (player->ray_dir_x < 0)
		{
			ray->step_x = -1;
			ray->side_dist_x = (player->x - ray->map_x) * ray->delta_dist_x;
		}
		else
		{
			ray->step_x = 1;
			ray->side_dist_x = (ray->map_x + 1.0 - player->x) * ray->delta_dist_x;
		}
		if (player->ray_dir_y < 0)
		{
			ray->step_y = -1;
			ray->side_dist_y = (player->y - ray->map_y) * ray->delta_dist_y;
		}
		else
		{
			ray->step_y = 1;
			ray->side_dist_y = (ray->map_y + 1.0 - player->y) * ray->delta_dist_y;
		}
		ray->hit = 0;
		while (ray->hit == 0)
		{
			if (ray->side_dist_x < ray->side_dist_y)
			{
				ray->side_dist_x += ray->delta_dist_x;
				ray->map_x += ray->step_x;
				ray->side = 0;
			}
			else
			{
				ray->side_dist_y += ray->delta_dist_y;
				ray->map_y += ray->step_y;
				ray->side = 1;
			}
			if (ray->side == 0)
				ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
			else
				ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
			if (map[ray->map_y][ray->map_x] == '1')
				ray->hit = 1;
		}
		ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
		ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
		if (ray->draw_start < 0)
			ray->draw_start = 0;
		ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
		if (ray->draw_end >= HEIGHT)
			ray->draw_end = HEIGHT - 1;
		draw_vertical_line(pixel, x, ray->draw_start, ray->draw_end, RED);
		x++;
	}

	/*printf("player->pdx = %f\n", player->pdx);
	printf("player->pdy = %f\n", player->pdy);
	printf("player->x = %f\n", player->x);
	printf("player->y = %f\n", player->y);
	printf("player->plane_x = %f\n", player->plane_x);
	printf("player->plane_y = %f\n", player->plane_y);*/
}

void	display_map(t_data *data, t_pixel *pixel, char **map)
{
	draw_ceil(pixel, data->info.ceil);
	draw_floor(pixel, data->info.floor);
	raycasting(&data->ray, pixel, &data->player, map);
	mlx_put_image_to_window(data->mlx, data->win, data->pixel.img, 0, 0);
}

/*
int    ft_recup_rgb_pixel(t_pixel *tex_infos, t_texture *tex, int pix_x, int pix_y)
{
    unsigned char    r;
    unsigned char    g;
    unsigned char    b;
    double            pixel_bit;

    tex_infos->addr = mlx_get_data_addr(tex->img, &tex_infos->bits_per_pixel,
            &tex_infos->line_length, &tex_infos->endian);
    pixel_bit = (pix_x * 4) + (tex->h * 4 * pix_y);
    if (pixel_bit < 0)
        return (rend->crgb);
    b = tex_infos->addr[(pix_x * 4) + (tex->h * 4 * pix_y)];
    g = tex_infos->addr[(pix_x * 4) + (tex->h * 4 * pix_y + 1)];
    r = tex_infos->addr[(pix_x * 4) + (tex->h * 4 * pix_y + 2)];
    return (rgb_to_int(r, g, b));
}

t_texture	side_wall(t_info *info, t_ray *ray, t_player *player)
{

	t_texture  tex;

	if (ray->side == 0 && player->ray_dir_x < 0)
		tex = info->n_tex;
	else if (ray->side == 0 && player->ray_dir_x > 0)
		tex = info->s_tex;
	else if (ray->side == 1 && player->ray_dir_y < 0)
		tex = info->e_tex;
	else if (ray->side == 1 && player->ray_dir_y > 0)
		tex = info->w_tex;
	return (tex);
}*/
