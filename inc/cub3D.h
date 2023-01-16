/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:03:21 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/16 13:12:37 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/inc/libft.h"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"

# include <fcntl.h>

typedef struct s_data
{
	char	**map;
	void	*mlx;
	void	*win;
}				t_data;

void	parse_map(char *av, t_data *l);
void	check_map(t_data *l);
void	put_map(t_data *l);
void	init_vars(t_data *l);
void	play(t_data *l);
int		close_win(t_data *l);

void	ft_error(t_data *l);

#endif
