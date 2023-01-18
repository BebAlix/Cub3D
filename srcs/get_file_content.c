/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:34:05 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/18 12:19:13 by chjoie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_parse_struct(t_parse *parse)
{
	free(parse->north_texture);
	free(parse->south_texture);
	free(parse->west_texture);
	free(parse->east_texture);
}

void	ft_parsing_error(t_parse *parse)
{	
	free_parse_struct(parse);
	printf("Error\nWrong Map parameter !!\n");
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
			return (0);
		else
		{
			ft_remove_n(str[i - 1]);
			return (1);
		}
	}
	return (0);
}

int	fill_param(char *line, t_parse *parse)
{
	char	**split_line;

	split_line = ft_split(line, ' ');
	if (check_splitted_line(split_line) == 0)
	{
		free_double_char(split_line);
		return (0);
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
		printf("line %s\n", split_line[1]);
		if (background_color(split_line, parse) == 0)
		{	
			free_double_char(split_line);
			return (0);
		}
	}
	else
	{
		free_double_char(split_line);
		return (0);
	}
	free_double_char(split_line);
	return (1);
}

int	check_all_param(t_parse *parse)
{
	if (parse->north_texture == NULL)
		return (0);
	if (parse->south_texture == NULL)
		return (0);
	if (parse->east_texture == NULL)
		return (0);
	if (parse->west_texture == NULL)
		return (0);
	else
		return (1);
}

int	check_line(char *line, t_parse *parse)
{
	if (parse->filled < 6)
	{
		if (ft_strncmp(line, "\n", 2) == 0)
			return (1);
		if (fill_param(line, parse) == 0)
			return (0);
		parse->filled++;
	}
	else if (check_all_param(parse) == 1)
		printf("besoin de parse la map\n");
	else
		return (0);
	return (1);
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
		parse->F[i] = -1;
		parse->C[i] = -1;
		i++;
	}
	return ;
}

void	content_error(int fd, char *line, t_parse *parse)
{
	free(line);
	line = get_next_line(fd);
	while (line)
	{	
		free(line);
		line = get_next_line(fd);
	}
	ft_parsing_error(parse);
}

int	first_line_map(char *line)
{
	int	x;

	x = 0;
	printf("line = %s\n", line);
	ft_remove_n(line);
	while (line[x] != '\0')
	{
		printf("line[x] = %c\n", line[x]);
		if (line[x] == '1' || line[x] == ' ')
			x++;
		else
			return (0);
	}
	return (1);
}

char	*go_to_map(int fd, char *line, t_parse *parse)
{
	while (!ft_strncmp(line, "\n", 2))
	{
		printf("line avant map = %s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	if (first_line_map(line) == 0)
		content_error(fd, line, parse);
	return (line);
}

void	get_file_content(char *filename, t_parse *parse)
{
	char	*line;
	int		fd;

	init_parse_struct(parse);
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (parse->filled == 6)
		{
			line = go_to_map(fd, line, parse);
			parse->filled++;
		}
		if (check_line(line, parse) == 0)
			content_error(fd, line, parse);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}
