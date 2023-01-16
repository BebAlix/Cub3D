/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_rlu.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 21:20:47 by equesnel          #+#    #+#             */
/*   Updated: 2022/09/01 01:23:56 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

long long	ft_putnbr_base_rlu(char *base, unsigned long long nb)
{
	unsigned long long		len;
	unsigned long long		len_base;

	len_base = ft_strlen_p(base);
	len = 0;
	if (nb >= len_base)
	{
		len += ft_putnbr_base_rl(base, (nb / len_base));
		len += ft_putchar_rl(base[nb % len_base]);
	}
	else
		len += ft_putchar_rl(base[nb]);
	return (len);
}
