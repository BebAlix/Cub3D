/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:43:07 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/28 14:24:32 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	rgb_to_int(int red, int green, int blue)
{
	return ((red * 65536) + (green * 256) + blue);
}

void	parsing(char *filename, t_parse *parse)
{
	get_file_content(filename, parse);
	parse->floor = rgb_to_int(parse->f[0], parse->f[1], parse->f[2]);
	parse->ceil = rgb_to_int(parse->c[0], parse->c[1], parse->c[2]);
}
