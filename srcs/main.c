/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:16:19 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/19 15:49:42 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_player_position(t_player *player, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E' || map[i][j] == 'S')
			{
				player->x = (i + 0.5) * 32;
				player->y = (j + 0.5) * 32;
			}
			j++;
		}
		i++;
	}
	player->pa =90;
}

void	init_vars(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3D");
	data->pixel.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->pixel.addr = mlx_get_data_addr(data->pixel.img, &data->pixel.bits_per_pixel,
			&data->pixel.line_length, &data->pixel.endian);
	init_player_position(&data->player, data->parse.map);
	//set_background(data->pixel);
	//raycasting
	display_map(data, data->pixel);
	// play(data);
	//closewindow
	mlx_put_image_to_window(data->mlx, data->win, data->pixel.img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	check_errors(argc, argv);
	parsing(argv[1], &data.parse);
	init_vars(&data);
	play(&data);
	return (0);
}

//math.h

// angle * (M_PI / 180); angle en radian