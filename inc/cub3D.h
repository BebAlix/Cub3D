/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:03:21 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/20 13:23:18 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"

# include <fcntl.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 600

# define BLUE 0x87CEEB
# define BROWN 0xBC8F8F
# define GREY 0xD3D3D3
# define WHITE 0xFFFFF0
# define RED 0xB22222

# define TRUE 1
# define FALSE 0

typedef struct s_parse
{
	char	*file_content;
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	int		f[3];
	int		c[3];
	int		filled;
	char	player_position;
	char	**map;
}				t_parse;

typedef struct s_pixel
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_pixel;

typedef struct s_player
{
	double	x;
	double	y;
	double	pdx;
	double	pdy;
	double	planeX;
	double	planeY;
	double	rayDirX;
	double	rayDirY;
	double	pa;
	double	cameraX;
}				t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_pixel	pixel;
	t_parse	parse;
	t_player	player;
}				t_data;

void	init_vars(t_data *data);
void	play(t_data *data);
int		close_win(t_data *data);
void	ft_error(t_data *data);

void	check_errors(int argc, char **argv);
int	check_valid_map(char **map, char *position);
void	parsing(char *filename, t_parse *parse);
void	get_file_content(char *filename, t_parse *parse);
int		background_color(char **tab, t_parse *parse);
void	error_msg(char *str);

void	set_background(t_pixel *pixel);
void	print_map(t_pixel pixel, t_parse *parse);
void	print_player(t_pixel pixel, t_player *player, double x, double y, int color);
void	print_zigouigoui(t_pixel pixel, t_player *player, double x, double y, int color);
void	display_map(t_data *data, t_pixel *pixel, char **map);

void	free_double_char(char **str);
void	free_parse_struct(t_parse *parse);

#endif
