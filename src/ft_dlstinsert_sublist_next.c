/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstinsert_sublist_next.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:21:30 by juportie          #+#    #+#             */
/*   Updated: 2025/06/03 16:09:30 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstinsert_sublist_next(t_dlst *lst, t_dlst *sublist)
{
	t_dlst	*sublist_last;

	if (!lst || !sublist)
		return ;
	sublist_last = ft_dlstlast(sublist);
	sublist->prev = lst;
	sublist_last->next = lst->next;
	if (lst->next)
		lst->next->prev = sublist_last;
	lst->next = sublist;
}
