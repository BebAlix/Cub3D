/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:28:29 by equesnel          #+#    #+#             */
/*   Updated: 2022/09/01 01:15:11 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*str;
	unsigned char	c1;

	c1 = (unsigned char) c;
	str = (char *) s;
	i = ft_strlen(s);
	if (str == 0)
		return (0);
	while (i > 0)
	{
		if (str[i] == c1)
			return (str + i);
		i--;
	}
	if (str[i] == c1)
		return (str + i);
	return (0);
}
