/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:34:05 by equesnel          #+#    #+#             */
/*   Updated: 2023/02/01 15:46:57 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_parsing_error(t_parse *parse)
{	
	free_parse_struct(parse);
	exit(1);
}

void	ft_remove_n(char *str)
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

int	fill_param(char *line, t_parse *parse)
{
	char	**split_line;

	split_line = ft_split(line, ' ');
	if (check_splitted_line(split_line) == 0)
	{
		free_double_char(split_line);
		return (FALSE);
	}
	if (!ft_strncmp(split_line[0], "NO", 3) && !parse->north_texture)
			parse->north_texture = ft_strdup(split_line[1]);
	else if (!ft_strncmp(split_line[0], "SO", 3) && !parse->south_texture)
			parse->south_texture = ft_strdup(split_line[1]);
	else if (!ft_strncmp(split_line[0], "WE", 3) && !parse->west_texture)
			parse->west_texture = ft_strdup(split_line[1]);
	else if (!ft_strncmp(split_line[0], "EA", 3) && !parse->east_texture)
			parse->east_texture = ft_strdup(split_line[1]);
	else if (!ft_strncmp(split_line[0], "F", 2) || !ft_strncmp(split_line[0], "C", 2))
	{
		if (background_color(split_line, parse) == 0)
		{	
			free_double_char(split_line);
			return (-2);
		}
	}
	else
	{
		free_double_char(split_line);
		return (FALSE);
	}
	free_double_char(split_line);
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

int	filled_file_content(char *line, t_parse *parse)
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
		if (!filled_file_content(line, parse))
			return (FALSE);
	}
	else
		return (FALSE);
	return (TRUE);
}

void	init_parse_struct(t_parse *parse)
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
	int	error = 0;
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

void	get_file_content(char *filename, t_parse *parse)
{
	char	*line;
	int		fd;
	int		check;

	check = 0;
	init_parse_struct(parse);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		error_msg("File doesn't exist");
		ft_parsing_error(parse);
	}
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
	parse->map = ft_split(parse->file_content, '\n');
	free(line);
	close(fd);
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
