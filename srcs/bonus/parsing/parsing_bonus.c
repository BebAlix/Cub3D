/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:43:07 by equesnel          #+#    #+#             */
/*   Updated: 2023/02/02 18:12:44 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	check_parsing_error(t_parse *parse)
{
	if (!parse->map)
	{
		error_msg("File content is not valid");
		ft_parsing_error(parse);
	}
	if (!check_valid_map(parse->map, &parse->player_position))
	{
		free_double_char(parse->map);
		error_msg("Map description is not valid");
		ft_parsing_error(parse);
	}
	if (check_xpm_texture(parse) == 0)
	{
		free_double_char(parse->map);
		error_msg("Texture are not xpm");
		ft_parsing_error(parse);
	}
}

static void	parse_file(int fd, t_parse *parse)
{
	char	*line;
	int		check;

	line = get_next_line(fd);
	while (line)
	{
		if (parse->filled == 6)
		{
			line = go_to_map(fd, line, parse);
			parse->filled++;
		}
		check = check_line(line, parse);
		if (check == -2)
			content_error(fd, line, parse, -2);
		else if (check == 0)
			content_error(fd, line, parse, 0);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

static void	init_parse_struct(t_parse *parse)
{
	int	i;

	i = 0;
	parse->north_texture = NULL;
	parse->south_texture = NULL;
	parse->east_texture = NULL;
	parse->west_texture = NULL;
	parse->filled = 0;
	while (i < 3)
	{
		parse->f[i] = -1;
		parse->c[i] = -1;
		i++;
	}
	parse->file_content = calloc(sizeof(char), 1);
	return ;
}

void	parsing(char *filename, t_parse *parse)
{
	int		fd;

	init_parse_struct(parse);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		error_msg("File doesn't exist");
		ft_parsing_error(parse);
	}
	parse_file(fd, parse);
	parse->map = ft_split(parse->file_content, '\n');
	check_parsing_error(parse);
}
