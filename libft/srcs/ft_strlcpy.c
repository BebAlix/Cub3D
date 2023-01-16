/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:28:52 by equesnel          #+#    #+#             */
/*   Updated: 2022/09/01 01:12:20 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		ls;

	ls = ft_strlen(src);
	i = -1;
	if (size == 0)
		return (ls);
	while (src[++i] && i < size - 1)
		dst[i] = src[i];
	dst[i] = 0;
	return (ls);
}
