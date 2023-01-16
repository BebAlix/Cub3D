/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 01:50:03 by equesnel          #+#    #+#             */
/*   Updated: 2022/09/01 16:04:46 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	z;
	size_t	x;

	i = -1;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[++i] && i < len)
	{
		if (big[i] == little[0])
		{
			z = i - 1;
			x = -1;
			while (big[++z] == little[++x] && z < len)
				if (little[x + 1] == '\0')
					return ((char *)big + i);
		}
	}
	return (0);
}
