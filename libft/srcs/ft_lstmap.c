/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:56:14 by equesnel          #+#    #+#             */
/*   Updated: 2022/04/14 01:20:47 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_lst	*ft_lstmap(t_lst *lst, void *(*f)(void *), void (*del)(void *))
{
	t_lst	*nl;
	t_lst	*t;

	if (!lst)
		return (NULL);
	t = ft_lstnew(f(lst->content));
	if (!t)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	lst = lst->next;
	nl = t;
	while (lst)
	{
		t = ft_lstnew(f(lst->content));
		if (!t)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&nl, t);
		lst = lst->next;
	}
	return (nl);
}
