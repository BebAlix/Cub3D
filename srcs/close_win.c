/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:13:06 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/16 13:18:38 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	free_map(t_data *l)
{
	int	i;

	i = 0;
	if (l->map)
	{
		while (l->map[i])
		{
			free(l->map[i]);
			i++;
		}
	}
	free(l->map);
}
/*
static void	destroy_image(t_data *l)
{

	return (0);
}*/

int	close_win(t_data *l)
{
	mlx_clear_window(l->mlx, l->win);
	//destroy_image(l);
	mlx_destroy_window(l->mlx, l->win);
	mlx_destroy_display(l->mlx);
	// free_map(l);
	free(l->mlx);
	exit(0);
}

void	ft_error(t_data *l)
{
	ft_printf("Error\nMap invalid !");
	free_map(l);
	exit(0);
}
