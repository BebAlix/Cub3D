/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:06:59 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/17 22:26:02 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	error_msg(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
}

static int	filled_c(t_parse *parse, char **color)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (parse->C[i] != -1)
		{
			error_msg("Color c is in double");
			return (0);
		}
		parse->C[i] = ft_atoi(color[i]);
		i++;
	}
	return (1);
}

static int	filled_color(char *name, t_parse *parse, char **color)
{
	int	i;

	i = 0;
	if (!ft_strncmp(name, "F", 2))
	{
		while (i < 3)
		{
			if (parse->F[i] != -1)
			{
				error_msg("Color F is in double");
				return (0);
			}
			parse->F[i] = ft_atoi(color[i]);
			i++;
		}
	}
	else if (!ft_strncmp(name, "c", 2))
		if (!filled_c(parse, color))
			return (0);
	return (1);
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
			printf("digit = %c\n", color[i][j]);
			if (!ft_isdigit(color[i][j]))
			{
				error_msg("Color need only digits");
				return (0);
			}
			j++;
		}
		i++;
	}
	if (i != 3)
	{
		error_msg("Color need 3 arguments");
		return (0);
	}
	return (1);
}

int	background_color(char **tab, t_parse *parse)
{
	char	**color;

	color = ft_split(tab[1], ',');
	if (!check_digit(color))
		return (0);
	if (!filled_color(tab[0], parse, color))
		return (0);
	free_double_char(color);
	return (1);
}
