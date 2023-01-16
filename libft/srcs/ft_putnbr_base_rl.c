/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_rl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 21:20:25 by equesnel          #+#    #+#             */
/*   Updated: 2022/09/01 01:23:41 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_putnbr_base_rl(char *base, long int nb)
{
	int		len;
	int		len_base;

	len_base = ft_strlen_p(base);
	len = 0;
	if (nb < 0)
	{
		nb = -nb;
		len += ft_putchar_rl('-');
	}
	if (nb >= len_base)
	{
		len += ft_putnbr_base_rl(base, (nb / len_base));
		len += ft_putchar_rl(base[nb % len_base]);
	}
	else
		len += ft_putchar_rl(base[nb]);
	return (len);
}
