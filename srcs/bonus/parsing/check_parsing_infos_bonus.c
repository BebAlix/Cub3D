/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing_infos_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:48:17 by chjoie            #+#    #+#             */
/*   Updated: 2023/02/02 17:45:33 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	first_line_map(char *line)
{
	int	x;

	x = 0;
	while (line[x] != '\0')
	{
		if (line[x] == '1' || line[x] == ' ' || line[x] == '\n')
			x++;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	check_all_param(t_parse *parse)
{
	if (parse->north_texture == NULL)
		return (FALSE);
	if (parse->south_texture == NULL)
		return (FALSE);
	if (parse->east_texture == NULL)
		return (FALSE);
	if (parse->west_texture == NULL)
		return (FALSE);
	else
		return (TRUE);
}

int	check_line(char *line, t_parse *parse)
{
	int	check;

	check = fill_param(line, parse);
	if (parse->filled < 6)
	{
		if (ft_strncmp(line, "\n", 2) == 0)
			return (TRUE);
		if (check == 0)
			return (FALSE);
		else if (check == -2)
			return (-2);
		parse->filled++;
	}
	else if (check_all_param(parse) == 1)
	{
		if (!fill_file_content(line, parse))
			return (FALSE);
	}
	else
		return (FALSE);
	return (TRUE);
}

static	int	check_xpm_extension(char *argv)
{
	char	*str;
	char	*s;
	int		len;

	len = ft_strlen(argv);
	str = argv + len - 4;
	s = argv + len - 5;
	if (ft_strncmp(str, ".xpm", 4) == 0)
		return (1);
	return (0);
}

int	check_xpm_texture(t_parse *parse)
{
	int	error;

	error = 0;
	if (check_xpm_extension(parse->north_texture) == 0)
		error++;
	if (check_xpm_extension(parse->south_texture) == 0)
		error++;
	if (check_xpm_extension(parse->east_texture) == 0)
		error++;
	if (check_xpm_extension(parse->west_texture) == 0)
		error++;
	if (error == 0)
		return (1);
	return (0);
}
