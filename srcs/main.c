/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:16:19 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/18 23:25:10 by equesnel         ###   ########.fr       */
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
				player->x = i + 0.5;
				player->y = j + 0.5;
			}
			j++;
		}
		i++;
	}
}

void	init_vars(t_data *data)
{
	t_pixel	pixel;

	pixel = data->pixel;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, width, height, "cub3D");
	pixel.img = mlx_new_image(data->mlx, width, height);
	pixel.addr = mlx_get_data_addr(pixel.img, &pixel.bits_per_pixel,
			&pixel.line_length, &pixel.endian);
	init_player_position(&data->player, data->parse.map);
	//set_background(pixel);
	//raycasting
	display_map(data, pixel);
	mlx_put_image_to_window(data->mlx, data->win, pixel.img, 0, 0);
	//closewindow
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
