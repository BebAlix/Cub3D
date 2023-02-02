/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:38:25 by chjoie            #+#    #+#             */
/*   Updated: 2023/02/02 18:12:45 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static int	check_items(char *line, int *player, char *position)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_strchr("10 ", line[i]))
			i++;
		else if (ft_strchr("NSWE", line[i]))
		{
			*player = *player + 1;
			*position = line[i];
			i++;
		}
		else
			return (FALSE);
	}
	return (TRUE);
}

static int	surrounded(char **map, int i, int j)
{
	if (j > (int)ft_strlen(map[i + 1]) || j > (int)ft_strlen(map[i - 1]))
		return (FALSE);
	if (!ft_strchr("0WSEN1", map[i - 1][j]) || map[i - 1][j] == '\0')
		return (FALSE);
	if (!ft_strchr("0WSEN1", map[i - 1][j + 1]) || map[i - 1][j + 1] == '\0')
		return (FALSE);
	if (!ft_strchr("0WSEN1", map[i - 1][j - 1]) || map[i - 1][j - 1] == '\0')
		return (FALSE);
	if (!ft_strchr("0WSEN1", map[i + 1][j]) || map[i + 1][j] == '\0')
		return (FALSE);
	if (!ft_strchr("0WSEN1", map[i + 1][j + 1]) || map[i + 1][j + 1] == '\0')
		return (FALSE);
	if (!ft_strchr("0WSEN1", map[i + 1][j - 1]) || map[i + 1][j - 1] == '\0')
		return (FALSE);
	if (!ft_strchr("0WSEN1", map[i][j - 1]) || map[i][j - 1] == '\0')
		return (FALSE);
	if (!ft_strchr("0WSEN1", map[i][j + 1]) || map[i][j - 1] == '\0')
		return (FALSE);
	return (TRUE);
}

static int	check_arround(char **map, int i, int j)
{
	int	size;

	size = 0;
	while (map[size])
		size++;
	if (i == 0 || j == 0)
		return (FALSE);
	if (i == size - 1)
		return (FALSE);
	if (j == (int)ft_strlen(map[i]))
		return (FALSE);
	if (!surrounded(map, i, j))
		return (FALSE);
	return (TRUE);
}

static int	check_wall(char **map)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (ft_strchr("0WSEN", map[i][j]))
			{
				if (!check_arround(map, i, j))
					return (FALSE);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (TRUE);
}

int	check_valid_map(char **map, char *position)
{
	int	i;
	int	player;
	int	error;

	error = 1;
	player = 0;
	i = 0;
	while (map[i])
	{
		if (!check_items(map[i], &player, position))
			return (FALSE);
		i++;
	}
	if (player != 1)
		return (FALSE);
	else if (!check_wall(map))
		return (FALSE);
	return (TRUE);
}
