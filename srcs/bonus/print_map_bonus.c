/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:53:01 by equesnel          #+#    #+#             */
/*   Updated: 2023/02/02 17:46:26 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	print_square(t_data *data, int x, int y, int color)
{
	int	y_max;
	int	x_max;

	y *= PADDING;
	x *= PADDING;
	y_max = y + PADDING;
	x_max = x + PADDING;
	while (y < y_max)
	{
		while (x < x_max)
		{
			my_mlx_pixel_put(&data->pixel, x, y, color);
			x++;
		}
		x -= PADDING;
		y++;
	}
}

void	print_player(t_data *data, double x, double y)
{
	x *= PADDING;
	y *= PADDING;
	my_mlx_pixel_put(&data->pixel, x, y, 0x000000);
	my_mlx_pixel_put(&data->pixel, x - 1, y - 1, 0x000000);
	my_mlx_pixel_put(&data->pixel, x - 1, y + 1, 0x000000);
	my_mlx_pixel_put(&data->pixel, x + 1, y - 1, 0x000000);
	my_mlx_pixel_put(&data->pixel, x + 1, y + 1, 0x000000);
}

char	*line(int len, int nb)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_calloc(sizeof(char), len + nb + 1);
	while (i < len)
	{
		str[i] = '2';
		i++;
	}
	while (i < len + nb)
	{
		str[i] = '2';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_line(char *map)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(map);
	str = ft_calloc(sizeof(char), len + 6 + 1);
	i = 0;
	while (i < 3)
		str[i++] = '2';
	j = 0;
	while (j < len)
	{
		str[i] = map[j];
		j++;
		i++;
	}
	while (i < len + 6)
		str[i++] = '2';
	str[i] = 0;
	return (str);
}

char	**change_map(char **map)
{
	char	**new_map;
	int		i;
	int		j;

	new_map = NULL;
	i = 0;
	while (map[i])
		i++;
	new_map = ft_calloc(sizeof(char *), i + 6 + 1);
	i = 0;
	new_map[0] = line(ft_strlen(map[0]), 6);
	new_map[1] = line(ft_strlen(map[0]), 6);
	new_map[2] = line(ft_strlen(map[0]), 6);
	i = 0;
	j = 3;
	while (map[i])
	{
		new_map[j] = new_line(map[i]);
		i++;
		j++;
	}
	new_map[j] = line(ft_strlen(map[i - 1]), 6);
	new_map[j + 1] = line(ft_strlen(map[i - 1]), 6);
	new_map[j + 2] = line(ft_strlen(map[i - 1]), 6);
	new_map[j + 3] = NULL;
	return (new_map);
}

void	print_map(t_data *data, char **map)
{
	char	**new_map;
	int		y;
	int		x;
	int		y_max;
	int		x_max;
	int		old_x;
	int		old_y;

	y = floor(data->player.y);
	x = floor(data->player.x);
	old_y = y;
	old_x = x;
	y_max = y + 6;
	x_max = x + 6;
	new_map = change_map(map);
	while (y < y_max)
	{
		while (x < x_max)
		{
			if (new_map[y][x] == '1')
				print_square(data, x - old_x, y - old_y, 0x000000);
			if (new_map[y][x] == '0'
			|| new_map[y][x] == 'N'
			|| new_map[y][x] == 'W'
			|| new_map[y][x] == 'E'
			|| new_map[y][x] == 'S')
				print_square(data, x - old_x, y - old_y, 0xffffff);
			x++;
		}
		x -= 6;
		y++;
	}
	print_player(data, 3.5, 3.5);
	free_double_char(new_map);
}
