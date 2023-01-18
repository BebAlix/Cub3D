/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:13:06 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/17 20:06:53 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_map_param(t_parse *parse)
{
	free(parse->north_texture);
	free(parse->south_texture);
	free(parse->east_texture);
	free(parse->west_texture);
}

int	close_win(t_data *data)
{
	//mlx_destroy_image(data->mlx, &data->pixel.img);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map_param(&data->parse);
	exit(0);
}

void	ft_error(t_data *data)
{
	(void)data;
	ft_putendl_fd("Error\nMap invalid !", 2);
	exit(0);
}
