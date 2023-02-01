/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjoie <chjoie@student.42angouleme.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:46:12 by chjoie            #+#    #+#             */
/*   Updated: 2023/02/01 16:46:46 by chjoie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_remove_n(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	if (str[x - 1] == '\n')
		str[x - 1] = '\0';
}

int	check_splitted_line(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i == 2 || i == 3)
	{
		if (ft_strncmp(str[i - 1], "\n", 2) && i == 3)
			return (FALSE);
		else
		{
			ft_remove_n(str[i - 1]);
			return (TRUE);
		}
	}
	return (FALSE);
}

void	content_error(int fd, char *line, t_parse *parse, int color)
{
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	if (color != -2)
		error_msg("File content is not valid");
	ft_parsing_error(parse);
}
