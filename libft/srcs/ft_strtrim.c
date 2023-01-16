/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:16:37 by equesnel          #+#    #+#             */
/*   Updated: 2022/09/11 17:57:53 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_check(char test, const char *set )
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (test == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		x;

	i = 0;
	x = 0;
	j = ft_strlen(s1);
	while (ft_check(s1[i], set) == 1)
		i++;
	while (ft_check(s1[j - 1], set) == 1)
		j--;
	if (s1[i] == 0 && i > j)
		i = j;
	str = malloc (sizeof (char) * (j - i) + 1);
	if (!str)
		return (NULL);
	while (i < j)
		str[x++] = s1[i++];
	str[x] = 0;
	return (str);
}
