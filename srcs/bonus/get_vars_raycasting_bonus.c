/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vars_raycasting_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:38:44 by equesnel          #+#    #+#             */
/*   Updated: 2023/02/02 17:46:35 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_perp_wall_dist(t_ray *ray, char **map)
{
	int	hit;

	hit = 0;
	while (hit == 0)
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
			hit = 1;
	}
}

void	get_delta_dist(t_ray *ray, t_player *player)
{
	if (player->ray_dir_x == 0)
		ray->delta_dist_x = 1000;
	else if (player->ray_dir_x != 0)
		ray->delta_dist_x = fabs(1 / player->ray_dir_x);
	if (player->ray_dir_y == 0)
		ray->delta_dist_y = 1000;
	else if (player->ray_dir_y != 0)
		ray->delta_dist_y = fabs(1 / player->ray_dir_y);
}

void	get_side_dist(t_ray *ray, t_player *player)
{
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
}

void	get_vertical_line_size(t_ray *ray)
{
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}

void	get_tex_x(t_ray *ray, t_player *player, t_texture texture)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = player->y + ray->perp_wall_dist * player->ray_dir_y;
	else
		wall_x = player->x + ray->perp_wall_dist * player->ray_dir_x;
	wall_x -= floor(wall_x);
	ray->tex_x = (int)(wall_x * (double)texture.w);
	if (ray->side == 0 && player->ray_dir_x > 0)
		ray->tex_x = texture.w - ray->tex_x - 1;
	if (ray->side == 1 && player->ray_dir_y < 0)
		ray->tex_x = texture.w - ray->tex_x - 1;
}
