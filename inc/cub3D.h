/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:03:21 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/17 20:43:40 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"

# include <fcntl.h>

# define width 800
# define height 600

typedef struct	s_parse
{
	char	**file_content;
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	int	F[3];
	int	C[3];
	int	filled;
	char	**map;
}				t_parse;

typedef struct	s_pixel
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_pixel;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_pixel	pixel;
	t_parse	parse;

}				t_data;

void	init_vars(t_data *l);
void	play(t_data *l);
int		close_win(t_data *l);
void	ft_error(t_data *l);

void    check_errors(int argc, char **argv);
void    parsing(char *filename, t_parse *parse);
void	get_file_content(char *filename, t_parse *parse);
int		background_color(char **tab, t_parse *parse);

void	free_double_char(char **str);

#endif
