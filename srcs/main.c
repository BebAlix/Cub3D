/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:16:19 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/20 15:02:31 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
				player->x = (x + 0.5);
				player->y = (y + 0.5);
			}
			x++;
		}
		y++;
	}
	printf("orientation = %c\n", orientation);
	if (orientation == 'N')
		player->pa = M_PI / 2.0;
	if (orientation == 'S')
		player->pa = (M_PI * 3.0) / 2.0;
	if (orientation == 'E')
		player->pa = M_PI * 2.0;
	if (orientation == 'W')
		player->pa = M_PI;
	player->pdx = 0.0;
	player->pdy = 0.1;
}

void	init_vars(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3D");
	data->pixel.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->pixel.addr = mlx_get_data_addr(data->pixel.img, &data->pixel.bits_per_pixel,
			&data->pixel.line_length, &data->pixel.endian);
	init_player_position(&data->player, data->parse.map, data->parse.player_position);
	//set_background(data->pixel);
	//raycasting
}

int	main(int argc, char **argv)
{
	t_data	data;

	printf("pi = %f\n", M_PI);
	check_errors(argc, argv);
	parsing(argv[1], &data.parse);
	init_vars(&data);
	display_map(&data, data.pixel);
	play(&data);
	return (0);
}

//math.h

// angle * (M_PI / 180); angle en radian