/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:58:53 by equesnel          #+#    #+#             */
/*   Updated: 2022/09/11 19:55:15 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_len_malloc(int n)
{
	int		i;
	int		neg;

	i = 1;
	neg = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		n = -n;
		neg++;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i + neg);
}

static void	ft_swap(char *str)
{
	int		i;
	int		x;
	char	swap;
	int		size;

	size = ft_strlen(str);
	i = 0;
	x = size - 1;
	if (str[0] == '-')
		i++;
	while (i < x)
	{
		swap = str[i];
		str[i] = str[x];
		str[x] = swap;
		i++;
		x--;
	}
}

static void	ft_change_str(char *str, int n, int i)
{
	while (n > 0)
	{
		str[++i] = (n % 10) + 48;
		n = n / 10;
	}
	if (str[0] == 0)
		str[0] = '0';
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = -1;
	str = ft_calloc(sizeof (char), ft_len_malloc(n));
	if (!str)
		return (NULL);
	if (n == -2147483648)
	{
		(ft_strlcpy(str, "-2147483648", 12));
		return (str);
	}
	if (n < 0)
	{
		str[++i] = '-';
		n = -n;
	}
	ft_change_str(str, n, i);
	ft_swap(str);
	return (str);
}
