/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlstip_add_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 07:09:04 by juportie          #+#    #+#             */
/*   Updated: 2025/03/04 08:48:58 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cdlstip_add_back(t_dlstip **lst, t_dlstip *new_node)
{
	t_dlstip	*last;

	if (new_node && lst)
	{
		if (!*lst)
		{
			*lst = new_node;
			new_node->prev = *lst;
		}
		last = (*lst)->prev;
		new_node->next = *lst;
		new_node->prev = last;
		last->next = new_node;
		(*lst)->prev = new_node;
	}
}
