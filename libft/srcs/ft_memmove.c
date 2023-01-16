/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:23:56 by equesnel          #+#    #+#             */
/*   Updated: 2022/09/01 01:13:07 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest1;
	const char	*src1;
	size_t		i;
	char		*enddest1;
	const char	*endsrc1;

	i = 0;
	src1 = src;
	dest1 = dest;
	enddest1 = dest1 + (n - 1);
	endsrc1 = src1 + (n - 1);
	if (!dest && !src)
		return (NULL);
	if (dest1 < src1)
	{
		while (i < n)
		{
			dest1[i] = src1[i];
			i++;
		}
	}
	else
		while (n-- != 0)
			*enddest1-- = *endsrc1--;
	return (dest);
}
