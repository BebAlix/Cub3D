/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:34:05 by equesnel          #+#    #+#             */
/*   Updated: 2023/02/02 17:45:32 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	fill_texture(char **split_line, t_parse *parse)
{
	if (!ft_strncmp(split_line[0], "NO", 3) && !parse->north_texture)
			parse->north_texture = ft_strdup(split_line[1]);
	else if (!ft_strncmp(split_line[0], "SO", 3) && !parse->south_texture)
			parse->south_texture = ft_strdup(split_line[1]);
	else if (!ft_strncmp(split_line[0], "WE", 3) && !parse->west_texture)
			parse->west_texture = ft_strdup(split_line[1]);
	else if (!ft_strncmp(split_line[0], "EA", 3) && !parse->east_texture)
			parse->east_texture = ft_strdup(split_line[1]);
	else if (!ft_strncmp(split_line[0], "F", 2)
		|| !ft_strncmp(split_line[0], "C", 2))
	{
		if (background_color(split_line, parse) == 0)
			return (-2);
	}
	else
		return (FALSE);
	return (TRUE);
}

int	fill_param(char *line, t_parse *parse)
{
	char	**split_line;
	int		check;

	check = 0;
	split_line = ft_split(line, ' ');
	if (check_splitted_line(split_line) == 0)
	{
		free_double_char(split_line);
		return (FALSE);
	}
	check = fill_texture(split_line, parse);
	free_double_char(split_line);
	if (check == -2)
		return (-2);
	if (check == 0)
		return (FALSE);
	return (TRUE);
}

int	fill_file_content(char *line, t_parse *parse)
{
	char	*tmp;
	int		i;

	i = 0;
	while (line[i] == ' ' && line[i])
		i++;
	if (line[i] == '\n' && line[i])
		return (FALSE);
	tmp = parse->file_content;
	parse->file_content = ft_strjoin(tmp, line);
	free(tmp);
	return (TRUE);
}
