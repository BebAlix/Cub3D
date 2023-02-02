/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:03:21 by equesnel          #+#    #+#             */
/*   Updated: 2023/02/02 18:23:30 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"

# include <fcntl.h>
# include <math.h>

# define WIDTH 1280
# define HEIGHT 720
# define SPEED 0.1
# define PADDING 8

# define TRUE 1
# define FALSE 0

typedef struct s_pixel
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_pixel;

typedef struct s_parse
{
	char	*file_content;
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	int		f[3];
	int		c[3];
	char	**map;
	int		filled;
	char	player_position;
}				t_parse;

typedef struct s_texture
{
	t_pixel		tex_info;
	int			w;
	int			h;
}				t_texture;

typedef struct s_info
{
	t_texture	n_tex;
	t_texture	s_tex;
	t_texture	e_tex;
	t_texture	w_tex;
	char		**map;
	int			ceil;
	int			floor;
}				t_info;

typedef struct s_ray
{
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_x;
}				t_ray;

typedef struct s_player
{
	double	x;
	double	y;
	double	pdx;
	double	pdy;
	double	plane_x;
	double	plane_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	camera_x;
	double	pa;
}				t_player;

typedef struct s_map
{
	char	**new_map;
	int		y;
	int		x;
	int		y_max;
	int		x_max;
	int		old_x;
	int		old_y;
}				t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_pixel		pixel;
	t_parse		parse;
	t_player	player;
	t_ray		ray;
	t_info		info;
	t_map		map;
}				t_data;


//parsing
void	parsing(char *filename, t_parse *parse);
void	check_errors(int argc, char **argv);
void	ft_error(t_data *data);
int		check_valid_map(char **map, char *position);
void	get_file_content(char *filename, t_parse *parse);
char	*go_to_map(int fd, char *line, t_parse *parse);
int		first_line_map(char *line);
int		fill_file_content(char *line, t_parse *parse);
int		fill_param(char *line, t_parse *parse);
int		background_color(char **tab, t_parse *parse);
void	content_error(int fd, char *line, t_parse *parse, int color);
void	check_parsing_error(t_parse *parse);
void	error_msg(char *str);
void	ft_parsing_error(t_parse *parse);
int		check_xpm_texture(t_parse *parse);
int		check_line(char *line, t_parse *parse);
int		check_splitted_line(char **str);

//init values
void	init_vars(t_data *data);
void	init_player(t_player *player, char **map, char orientation);

// raycasting
void	raycasting(t_ray *ray, t_pixel *pixel, t_player *player, t_info *info);
void	get_tex_x(t_ray *ray, t_player *player, t_texture texture);
void	get_vertical_line_size(t_ray *ray);
void	get_side_dist(t_ray *ray, t_player *player);
void	get_delta_dist(t_ray *ray, t_player *player);
void	get_perp_wall_dist(t_ray *ray, char **map);

//play and display image
void	play(t_data *data);
void	display_map(t_data *data, t_pixel *pixel, t_info *info);
void	my_mlx_pixel_put(t_pixel *pixel, int x, int y, int color);

// close program
int		close_win(t_data *data);
void	free_parse_struct(t_parse *parse);
void	free_double_char(char **str);

//bonus
void	print_map(t_data *data, t_map m, char **map);
char	**change_map(char **map);
void	ft_mouse(t_data *data);

#endif
