/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstremove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:36:18 by juportie          #+#    #+#             */
/*   Updated: 2025/03/17 17:11:15 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstremove(t_dlst **node)
{
	t_dlst	*prev;
	t_dlst	*next;

	if (node && *node)
	{
		prev = (*node)->prev;
		next = (*node)->next;
		free((*node)->content);
		(*node)->content = NULL;
		free(*node);
		if (prev == NULL)
			*node = next;
		else
			prev->next = next;
		if (next != NULL)
			next->prev = prev;
	}
}
