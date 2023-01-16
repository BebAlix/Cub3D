/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:09:41 by equesnel          #+#    #+#             */
/*   Updated: 2022/04/13 18:25:47 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*l;

	l = *lst;
	if (l)
	{
		while (l->next)
			l = l->next;
		l->next = new;
	}
	else
		*lst = new;
}
