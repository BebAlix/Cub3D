/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:37:42 by equesnel          #+#    #+#             */
/*   Updated: 2023/02/01 15:51:00 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static unsigned int	my_mlx_get_color(t_pixel *tex_info, int x, int y)
{
	char	*dst;

	dst = tex_info->addr + (y * tex_info->line_length + x
			* (tex_info->bits_per_pixel / 8));
	return (*(unsigned int *) dst);
}

static void	draw_line_texture(t_ray *ray, t_texture texture,
	t_pixel *pixel, int x)
{
	double	step;
	double	tex_pos;
	int		color;
	int		tex_y;
	int		y;

	step = 1.0 * texture.h / ray->line_height;
	tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_y = (int)tex_pos;
		tex_pos += step;
		color = my_mlx_get_color(&texture.tex_info, ray->tex_x, tex_y);
		my_mlx_pixel_put(pixel, x, y, color);
		y++;
	}
}

static t_texture	side_wall(t_info *info, t_ray *ray, t_player *player)
{
	if (ray->side == 0 && player->ray_dir_x < 0)
		return (info->n_tex);
	if (ray->side == 0 && player->ray_dir_x > 0)
		return (info->s_tex);
	if (ray->side == 1 && player->ray_dir_y < 0)
		return (info->e_tex);
	if (ray->side == 1 && player->ray_dir_y > 0)
		return (info->w_tex);
	return (info->s_tex);
}

void	raycasting(t_ray *ray, t_pixel *pixel, t_player *player, t_info *info)
{
	t_texture	texture;
	int			x;

	x = 0;
	while (x < WIDTH)
	{
		player->camera_x = (2 * x) / (double) WIDTH - 1;
		player->ray_dir_x = player->pdx + player->plane_x * player->camera_x;
		player->ray_dir_y = player->pdy + player->plane_y * player->camera_x;
		ray->map_x = (int) player->x;
		ray->map_y = (int) player->y;
		get_delta_dist(ray, player);
		get_side_dist(ray, player);
		get_perp_wall_dist(ray, info->map);
		get_vertical_line_size(ray);
		texture = side_wall(info, ray, player);
		get_tex_x(ray, player, texture);
		draw_line_texture(ray, texture, pixel, x);
		x++;
	}
}
