/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstinsert_next.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:21:30 by juportie          #+#    #+#             */
/*   Updated: 2025/05/26 16:12:57 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstinsert_next(t_dlst **lst, t_dlst *new_node)
{
	if (new_node && lst)
	{
		if (*lst)
		{
			new_node->prev = *lst;
			new_node->next = (*lst)->next;
			if ((*lst)->next)
				(*lst)->next->prev = new_node;
			(*lst)->next = new_node;
		}
		else
			*lst = new_node;
	}
}
