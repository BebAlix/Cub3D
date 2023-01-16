/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:34:05 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/16 13:18:03 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_extension(char *av)
{
	char	*str;
	int		len;

	len = ft_strlen(av);
	str = av + len - 4;
	if (ft_strncmp(str, ".cub", 4) == 0)
		return ;
	ft_printf("Error\nWrong map extension !");
	exit(0);
}

static int	len_map(char *av, t_data *l)
{
	int		len;
	int		fd;
	int		i;
	char	*tmp;

	tmp = ft_calloc(sizeof(char), 1);
	if (!tmp)
		return (0);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error(l);
	i = 1;
	len = 0;
	while (i)
	{
		i = read(fd, tmp, 1);
		if (i == -1)
			ft_error(l);
		len++;
	}
	free (tmp);
	tmp = NULL;
	if (close(fd) == -1)
		ft_error(l);
	return (len);
}

void	parse_map(char *av, t_data *l)
{
	int		len;
	int		fd;
	int		i;
	char	*tmp;

	l->map = NULL;
	tmp = NULL;
	check_extension(av);
	len = len_map(av, l);
	tmp = ft_calloc(sizeof(char), len);
	if (!tmp)
		return ;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error(l);
	i = read(fd, tmp, len);
	if (i == -1)
		return ;
	l->map = ft_split(tmp, '\n');
	if (close(fd) == -1)
		ft_error(l);
	free (tmp);
	tmp = NULL;
}
