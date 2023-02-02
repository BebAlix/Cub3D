/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_color_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:06:59 by equesnel          #+#    #+#             */
/*   Updated: 2023/02/02 17:45:34 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	filled_c(t_parse *parse, char **color)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (parse->c[i] != -1)
		{
			error_msg("Color c is in double");
			return (FALSE);
		}
		parse->c[i] = ft_atoi(color[i]);
		i++;
	}
	return (TRUE);
}

static int	filled_color(char *name, t_parse *parse, char **color)
{
	int	i;

	i = 0;
	if (!ft_strncmp(name, "F", 2))
	{
		while (i < 3)
		{
			if (parse->f[i] != -1)
			{
				error_msg("Color F is in double");
				return (FALSE);
			}
			parse->f[i] = ft_atoi(color[i]);
			i++;
		}
	}
	if (!ft_strncmp(name, "C", 2))
		if (!filled_c(parse, color))
			return (FALSE);
	return (TRUE);
}

static int	check_size(char *color)
{
	char	*base;
	int		i;

	base = "255";
	i = 0;
	if (ft_strlen(color) > 3)
		return (FALSE);
	if (ft_strlen(color) < 3)
		return (TRUE);
	while (color[i])
	{
		if (color[i] == base[i])
			i++;
		else if (color[i] > base[i])
			return (FALSE);
		else
			return (TRUE);
	}
	return (TRUE);
}

static int	check_digit(char **color)
{
	int		i;
	int		j;

	i = 0;
	while (color[i])
	{
		j = 0;
		while (color[i][j])
		{
			if (!ft_isdigit(color[i][j]) || !check_size(color[i]))
			{
				error_msg("Color need only digits between 0 and 255");
				return (FALSE);
			}
			j++;
		}
		i++;
	}
	if (i != 3)
	{
		error_msg("Color need 3 arguments");
		return (FALSE);
	}
	return (TRUE);
}

int	background_color(char **tab, t_parse *parse)
{
	char	**color;

	color = ft_split(tab[1], ',');
	if (!check_digit(color) || !filled_color(tab[0], parse, color))
	{
		free_double_char(color);
		return (FALSE);
	}
	free_double_char(color);
	return (TRUE);
}
