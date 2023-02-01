/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:08:37 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/28 14:13:21 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_parsing_error(t_parse *parse)
{	
	free_parse_struct(parse);
	exit(1);
}

static void	check_nb_arg(int argc)
{
	if (argc != 2)
	{
		ft_putendl_fd("Error\n", 2);
		ft_putendl_fd("Wrong number of arguments !", 2);
		exit(1);
	}
}

static void	check_extension(char *argv)
{
	char	*str;
	char	*s;
	int		len;

	len = ft_strlen(argv);
	str = argv + len - 4;
	s = argv + len - 5;
	if (ft_strncmp(str, ".cub", 4) != 0)
	{
		ft_putendl_fd("Error\n", 2);
		ft_putendl_fd("Wrong map extension !", 2);
		exit(1);
	}
	if (ft_strncmp(s, "/.cub", 4) == 0)
	{
		ft_putendl_fd("Error\n", 2);
		ft_putendl_fd("Wrong map extension !", 2);
		exit(1);
	}
}

void	check_errors(int argc, char **argv)
{
	check_nb_arg(argc);
	check_extension(argv[1]);
}
