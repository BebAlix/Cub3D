/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:42:24 by equesnel          #+#    #+#             */
/*   Updated: 2023/02/02 18:13:55 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	free_double_char(char **str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		free(str[x]);
		str[x] = NULL;
		x++;
	}
	free(str);
	str = NULL;
}

void	free_parse_struct(t_parse *parse)
{
	free(parse->north_texture);
	free(parse->south_texture);
	free(parse->west_texture);
	free(parse->east_texture);
	free(parse->file_content);
}
