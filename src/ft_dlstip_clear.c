/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  ft_dlstip_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 07:12:06 by juportie          #+#    #+#             */
/*   Updated: 2025/03/04 07:18:06 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstip_clear(t_dlstip **lst)
{
	t_dlstip	*node;
	t_dlstip	*tail;

	if (lst == NULL || *lst == NULL)
		return ;
	tail = (*lst)->prev;
	while (*lst)
	{
		node = *lst;
		if (*lst != tail)
			*lst = node->next;
		else
			*lst = NULL;
		free(node->content);
		node->content = NULL;
		free(node);
		node = NULL;
	}
}
