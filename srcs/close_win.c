/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:13:06 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/16 18:15:42 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	free_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
	}
	free(data->map);
}
/*
static void	destroy_image(t_data *data)
{

	return (0);
}*/

int	close_win(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	//destroy_image(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	// free_map(data);
	free(data->mlx);
	exit(0);
}

void	ft_error(t_data *data)
{
	ft_putendl_fd("Error\nMap invalid !", 2);
	free_map(data);
	exit(0);
}
