/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:13:06 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/19 13:02:14 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	destroy_texture_img(void *mlx, t_info *map_info)
{
	mlx_destroy_image(mlx, map_info->n_tex.tex_info.img);
	mlx_destroy_image(mlx, map_info->s_tex.tex_info.img);
	mlx_destroy_image(mlx, map_info->e_tex.tex_info.img);
	mlx_destroy_image(mlx, map_info->w_tex.tex_info.img);
}

int	close_win(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	destroy_texture_img(data->mlx, &data->info);
	mlx_destroy_image(data->mlx, data->pixel.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_parse_struct(&data->parse);
	free_double_char(data->parse.map);
	exit(1);
}

void	ft_error(t_data *data)
{
	(void)data;
	ft_putendl_fd("Error\nMap invalid !", 2);
	exit(1);
}
