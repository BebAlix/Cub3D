/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:17:24 by equesnel          #+#    #+#             */
/*   Updated: 2022/09/01 01:21:38 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	nbline(char const *s, char c)
{
	int	i;
	int	nbl;

	i = 0;
	nbl = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			nbl++;
		while (s[i] != c && s[i])
			i++;
	}
	return (nbl);
}

static int	nbcolumn(char const *s, char c, int len)
{
	int	i;
	int	nbc;
	int	x;

	x = 0;
	i = 0;
	nbc = 0;
	while (s[i] == c)
		i++;
	while (x < len)
	{
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c)
			i++;
		x++;
	}
	while (s[i] != c && s[i])
	{
		i++;
		nbc++;
	}
	return (nbc);
}

static int	ft_start(char const *s, char c, int len)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (x < len && s[i])
	{
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c)
			i++;
		x++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	char	**str;

	len = nbline(s, c);
	i = -1;
	if (s[0] == 0)
	{
		str = ft_calloc(sizeof(char *), 1);
		if (!str)
			return (NULL);
		return (str);
	}
	str = ft_calloc(sizeof(char *), len + 1);
	if (!str)
		return (NULL);
	while (++i < len)
		str[i] = ft_substr(s, ft_start(s, c, i), nbcolumn(s, c, i));
	return (str);
}
