/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:16:19 by equesnel          #+#    #+#             */
/*   Updated: 2023/01/31 14:59:35 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_data	data;

	check_errors(argc, argv);
	parsing(argv[1], &data.parse);
	init_vars(&data);
	frame(&data);
	play(&data);
	return (0);
}
