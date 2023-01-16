/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:52:54 by equesnel          #+#    #+#             */
/*   Updated: 2022/09/01 01:24:36 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

char	*ft_join(int fd, char *str)
{
	char	*buf;
	int		i;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	i = 1;
	while (!ft_search_line(str) && i)
	{
		i = read(fd, buf, BUFFER_SIZE);
		buf[i] = '\0';
		str = ft_strjoin_gnl(str, buf);
	}
	free (buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*save[1024];
	char		*line;
	char		*str;
	int			len;

	if (!save[fd])
	{
		save[fd] = malloc(1);
		if (fd < 0 || BUFFER_SIZE < 1 || read(fd, save[fd], 0) < 0 || !save[fd])
			return (free(save[fd]), NULL);
		save[fd][0] = '\0';
	}
	str = ft_join(fd, save[fd]);
	len = check_len(str);
	line = ft_substr_gnl(str, 0, len);
	save[fd] = ft_substr_gnl(str, len, ft_strlen_gnl(str) - len);
	free(str);
	return (line);
}
