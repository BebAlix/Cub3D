/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:03:43 by equesnel          #+#    #+#             */
/*   Updated: 2022/09/01 01:18:07 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dest;
	int		i;

	i = -1;
	len = ft_strlen(s);
	dest = ft_calloc(sizeof (char), len + 1);
	if (!dest)
		return (NULL);
	while (s[++i])
		dest[i] = s[i];
	return (dest);
}
