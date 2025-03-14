/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:54:07 by juportie          #+#    #+#             */
/*   Updated: 2025/03/14 15:54:39 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cdlstadd_front(t_dlst **lst, t_dlst *new_node)
{
	if (new_node && lst)
	{
		if (!*lst)
		{
			*lst = new_node;
			new_node->prev = *lst;
		}
		new_node->next = *lst;
		new_node->prev = (*lst)->prev;
		(*lst)->prev->next = new_node;
		(*lst)->prev = new_node;
		*lst = new_node;
	}
}
