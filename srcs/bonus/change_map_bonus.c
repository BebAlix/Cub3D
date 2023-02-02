/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:22:51 by equesnel          #+#    #+#             */
/*   Updated: 2023/02/02 18:24:25 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

char	*line(int len, int nb)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_calloc(sizeof(char), len + nb + 1);
	while (i < len)
	{
		str[i] = '2';
		i++;
	}
	while (i < len + nb)
	{
		str[i] = '2';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_line(char *map)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(map);
	str = ft_calloc(sizeof(char), len + 6 + 1);
	i = 0;
	while (i < 3)
		str[i++] = '2';
	j = 0;
	while (j < len)
	{
		str[i] = map[j];
		j++;
		i++;
	}
	while (i < len + 6)
		str[i++] = '2';
	str[i] = 0;
	return (str);
}

char	**change_map(char **map)
{
	char	**new_map;
	int		i;
	int		j;

	i = 0;
	while (map[i])
		i++;
	new_map = ft_calloc(sizeof(char *), i + 6 + 1);
	i = 0;
	new_map[0] = line(ft_strlen(map[0]), 6);
	new_map[1] = line(ft_strlen(map[0]), 6);
	new_map[2] = line(ft_strlen(map[0]), 6);
	i = 0;
	j = 3;
	while (map[i])
	{
		new_map[j] = new_line(map[i]);
		i++;
		j++;
	}
	new_map[j] = line(ft_strlen(map[i - 1]), 6);
	new_map[j + 1] = line(ft_strlen(map[i - 1]), 6);
	new_map[j + 2] = line(ft_strlen(map[i - 1]), 6);
	new_map[j + 3] = NULL;
	return (new_map);
}
