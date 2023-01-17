/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:16:19 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/17 14:20:39 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_win(data);
/*	if (keycode == XK_w)
		move;
	if (keycode == XK_a)
		move;
	if (keycode == XK_s)
		move;
	if (keycode == XK_d)
		move*/
	return (0);
}


void	my_mlx_pixel_put(t_pixel *pixel, int x, int y, int color)
{
	char	*dst;

	dst = pixel->addr + (y * pixel->line_length + x * (pixel->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	set_background(t_pixel pixel)
{
	int	x;
	int	y;
	int	middle;

	x = 0;
	y = 0;
	middle = height / 2;
	while (y < middle)
	{
		my_mlx_pixel_put(&pixel, x, y, 0x87CEEB);
		if (x == width)
		{
			x = 0;
			y++;
		}
		x++;
	}
	while (y < height)
	{
		my_mlx_pixel_put(&pixel, x, y, 0xBC8F8F);
		if (x == width)
		{
			x = 0;
			y++;
		}
		x++;
	}
}

void	play(t_data *data)
{
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 17, 0, close_win, data);
	mlx_loop(data->mlx);
}

void	init_vars(t_data *data)
{
	t_pixel pixel;

	pixel = data->pixel;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, width, height, "cub3D");
	pixel.img = mlx_new_image(data->mlx, width, height);
	pixel.addr = mlx_get_data_addr(pixel.img, &pixel.bits_per_pixel, &pixel.line_length, &pixel.endian);
	set_background(pixel);
	//raycasting
	mlx_put_image_to_window(data->mlx, data->win, pixel.img, 0, 0);
	//closewindow
}

int main(int argc, char **argv)
{
	t_data	data;
	
	check_errors(argc, argv);
	parsing(argv[1], &data.parse);
	init_vars(&data);
	play(&data);
	return (0);
}
