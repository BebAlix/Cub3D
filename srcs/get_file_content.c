/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:34:05 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/17 15:24:09 by chjoie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	fill_param(char *line, t_parse *parse)
{
	(void) line;
	(void) parse;
	return ;
}

void	check_line(char *line, t_parse *parse)
{
	
	if (parse->filled < 6)
	{
		if (ft_strncmp(line, "\n", 1) == 0)
			return ;
		fill_param(line, parse);
		parse->filled++;
	}

}
void	get_file_content(char *filename, t_parse *parse)
{
	char *line;
	int  fd;
	
	parse->filled = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		check_line(line, parse);
		printf("line = %s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	
}

/*
static int	len_file(char *filename, t_data *data)
{
	int		len;
	int		fd;
	int		i;
	char	*tmp;

	(void)data;
	tmp = ft_calloc(sizeof(char), 1);
	if (!tmp)
		return (0);
	fd = open(filename, O_RDONLY);
	// if (fd == -1)
	// 	ft_error(data);
	i = 1;
	len = 0;
	while (i)
	{
		i = read(fd, tmp, 1);
		// if (i == -1)
		// 	ft_error(data);
		len++;
	}
	free (tmp);
	tmp = NULL;
	// if (close(fd) == -1)
	// 	ft_error(data);
	return (len);
}

void	get_file_content(char *filename, t_data *data)
{
	int		len;
	int		fd;
	int		i;
	char	*tmp;

	tmp = NULL;
	len = len_file(filename, data);
	if (!len)
		return ;
	tmp = ft_calloc(sizeof(char), len);
	if (!tmp)
		return ;
	fd = open(filename, O_RDONLY);
	// if (fd == -1)
	// 	//ft_error(data);
	i = read(fd, tmp, len);
	if (i == -1)
		return ;
	data->parse.file_content = ft_split(tmp, '\n');
	// if (close(fd) == -1)
		//ft_error(data);
	free (tmp);
	tmp = NULL;
}
*/
