/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:55:31 by equesnel          #+#    #+#             */
/*   Updated: 2022/09/01 01:24:48 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_search_line(const char *s)
{
	int	i;

	if (!s[0])
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

int	check_len(char *save)
{
	int	len;

	len = 0;
	while (save[len] && save[len] != '\n' )
		len++;
	len++;
	return (len);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		x;
	char	*str;

	i = 0;
	x = -1;
	str = malloc (sizeof (char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2)) + 1);
	if (!str)
		return (NULL);
	while (s1[++x])
		str[x] = (s1[x]);
	while (s2[i])
		str[x++] = s2[i++];
	str[x] = '\0';
	free(s1);
	return (str);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = -1;
	if (len > ft_strlen_gnl(s))
		len = ft_strlen_gnl(s);
	if (start > ft_strlen_gnl(s))
		len = 0;
	if (!len)
		return (NULL);
	str = malloc(sizeof (char) * len + 1);
	if (!str)
		return (NULL);
	while (start + ++i < start + len)
		str[i] = s[start + i];
	str[i] = '\0';
	return (str);
}
