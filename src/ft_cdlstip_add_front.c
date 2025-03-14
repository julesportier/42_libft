/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlstip_add_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 07:10:27 by juportie          #+#    #+#             */
/*   Updated: 2025/03/04 08:46:20 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cdlstip_add_front(t_dlstip **lst, t_dlstip *new_node)
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
