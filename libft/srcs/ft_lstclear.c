/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:25:13 by equesnel          #+#    #+#             */
/*   Updated: 2022/04/13 22:31:27 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstclear(t_lst **lst, void (*del)(void*))
{
	t_lst	*l;

	l = *lst;
	while (*lst)
	{
		*lst = l->next;
		del(l->content);
		free(l);
		l = *lst;
	}
}
