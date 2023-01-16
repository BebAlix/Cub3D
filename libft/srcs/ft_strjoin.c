/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:01:45 by equesnel          #+#    #+#             */
/*   Updated: 2022/09/01 01:19:18 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		lt;
	int		x;
	char	*str;

	i = 0;
	x = -1;
	if (!s1)
		return (NULL);
	lt = ft_strlen(s1) + ft_strlen(s2);
	str = malloc (sizeof (char) * lt + 1);
	if (!str)
		return (NULL);
	while (s1[++x])
		str[x] = s1[x];
	while (s2[i])
		str[x++] = s2[i++];
	str[x] = 0;
	return (str);
}
