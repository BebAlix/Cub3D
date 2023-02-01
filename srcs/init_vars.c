/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:26:39 by equesnel          #+#    #+#             */
/*   Updated: 2023/02/01 15:43:08 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_orientation_n_s(t_player *player, char orientation)
{
	if (orientation == 'N')
	{
		player->pdx = -1;
		player->pdy = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	if (orientation == 'S')
	{
		player->pdx = 1;
		player->pdy = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
}

void	init_orientation_e_w(t_player *player, char orientation)
{
	if (orientation == 'E')
	{
		player->pdx = 0;
		player->pdy = -1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	if (orientation == 'W')
	{
		player->pdx = 0;
		player->pdy = 1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
}

void	init_player_position(t_player *player, char **map, char orientation)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == orientation)
			{
				player->x = x + 0.5;
				player->y = y + 0.5;
			}
			x++;
		}
		y++;
	}
	init_orientation_n_s(player, orientation);
	init_orientation_e_w(player, orientation);
}

int	rgb_to_int(int red, int green, int blue)
{
	return ((red << 16) + (green << 8) + blue);
}

int	init_info(t_parse parse, t_info *info, void *mlx)
{
	info->n_tex.tex_info.img = NULL;
	info->s_tex.tex_info.img = NULL;
	info->e_tex.tex_info.img = NULL;
	info->w_tex.tex_info.img = NULL;
	info->n_tex.tex_info.img = mlx_xpm_file_to_image(mlx, parse.north_texture, &info->n_tex.w, &info->n_tex.h);
	if (!info->n_tex.tex_info.img)
		return (1);
	info->s_tex.tex_info.img = mlx_xpm_file_to_image(mlx, parse.south_texture, &info->s_tex.w, &info->s_tex.h);
	if (!info->s_tex.tex_info.img)
		return (1);
	info->e_tex.tex_info.img = mlx_xpm_file_to_image(mlx, parse.east_texture, &info->e_tex.w, &info->e_tex.h);
	if (!info->e_tex.tex_info.img)
		return (1);
	info->w_tex.tex_info.img = mlx_xpm_file_to_image(mlx, parse.west_texture, &info->w_tex.w, &info->w_tex.h);
	if (!info->w_tex.tex_info.img)
		return (1);
	info->n_tex.tex_info.addr = mlx_get_data_addr(info->n_tex.tex_info.img, &info->n_tex.tex_info.bits_per_pixel,
			&info->n_tex.tex_info.line_length, &info->n_tex.tex_info.endian);
	info->s_tex.tex_info.addr = mlx_get_data_addr(info->s_tex.tex_info.img, &info->s_tex.tex_info.bits_per_pixel,
			&info->s_tex.tex_info.line_length, &info->s_tex.tex_info.endian);
	info->e_tex.tex_info.addr = mlx_get_data_addr(info->e_tex.tex_info.img, &info->e_tex.tex_info.bits_per_pixel,
			&info->e_tex.tex_info.line_length, &info->e_tex.tex_info.endian);
	info->w_tex.tex_info.addr = mlx_get_data_addr(info->w_tex.tex_info.img, &info->w_tex.tex_info.bits_per_pixel,
			&info->w_tex.tex_info.line_length, &info->w_tex.tex_info.endian);
	info->map = parse.map;
	info->floor = rgb_to_int(parse.f[0], parse.f[1], parse.f[2]);
	info->ceil = rgb_to_int(parse.c[0], parse.c[1], parse.c[2]);
	return (0);
}

void	init_vars(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		close_win(data);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3D");
	data->pixel.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->pixel.addr = mlx_get_data_addr(data->pixel.img, &data->pixel.bits_per_pixel,
			&data->pixel.line_length, &data->pixel.endian);
	if (init_info(data->parse, &data->info, data->mlx) == 1)
	{
		ft_putendl_fd("Error\nTexture does not exit !", 2);
		close_win(data);
	}
	init_player_position(&data->player, data->parse.map, data->parse.player_position);
}
