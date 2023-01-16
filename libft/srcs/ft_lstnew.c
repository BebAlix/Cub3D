/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:01:48 by equesnel          #+#    #+#             */
/*   Updated: 2022/04/13 17:01:55 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_lst	*ft_lstnew(void *content)
{
	t_lst	*l;

	l = malloc(sizeof (t_lst));
	if (!l)
		return (NULL);
	l->content = content;
	l->next = NULL;
	return (l);
}
