/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstremove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:36:18 by juportie          #+#    #+#             */
/*   Updated: 2025/05/06 17:08:49 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstremove(t_dlst **node, void del(void *))
{
	t_dlst	*prev;
	t_dlst	*next;

	if (node && *node)
	{
		prev = (*node)->prev;
		next = (*node)->next;
		del((*node)->content);
		free(*node);
		if (prev == NULL)
			*node = next;
		else
			prev->next = next;
		if (next != NULL)
			next->prev = prev;
	}
}
