/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:08:37 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/17 20:30:32 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_nb_arg(int argc)
{
	if (argc != 2)
	{
		ft_putendl_fd("Error\n", 2);
		ft_putendl_fd("Wrong number of arguments !", 2);
		exit(0);
	}
}

static void	check_extension(char *argv)
{
	char	*str;
	int		len;

	len = ft_strlen(argv);
	str = argv + len - 4;
	if (ft_strncmp(str, ".cub", 4) != 0)
	{
		ft_putendl_fd("Error\n", 2);
		ft_putendl_fd("Wrong map extension !", 2);
		exit(0);
	}
}

void	check_errors(int argc, char **argv)
{
	check_nb_arg(argc);
	check_extension(argv[1]);
}
