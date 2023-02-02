/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:46:12 by chjoie            #+#    #+#             */
/*   Updated: 2023/02/02 18:12:43 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_parsing_error(t_parse *parse)
{	
	free_parse_struct(parse);
	exit(1);
}

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

char	*go_to_map(int fd, char *line, t_parse *parse)
{
	while (!ft_strncmp(line, "\n", 2))
	{
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
		{
			error_msg("There is no map in file");
			ft_parsing_error(parse);
		}
	}
	if (first_line_map(line) == 0)
		content_error(fd, line, parse, 0);
	return (line);
}
