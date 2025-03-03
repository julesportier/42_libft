/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlsti_add_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:20:40 by juportie          #+#    #+#             */
/*   Updated: 2025/03/03 12:37:55 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cdlsti_add_front(t_dlsti **lst, t_dlsti *new_node)
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
