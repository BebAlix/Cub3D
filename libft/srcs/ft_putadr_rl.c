/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr_rl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:10:03 by equesnel          #+#    #+#             */
/*   Updated: 2022/09/01 01:23:27 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

long long	ft_putadr_rl(unsigned long long adr)
{
	int	len;

	len = 0;
	if (adr == 0)
		return (ft_putstr_rl("(nil)"));
	len += ft_putstr_rl("0x");
	len += ft_putnbr_base_rlu("0123456789abcdef", adr);
	return (len);
}
