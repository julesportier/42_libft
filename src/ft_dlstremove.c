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

void	ft_dlstremove(
	t_dlst *node,
	void del_content(void *),
	void del_node(void *))
{
	t_dlst	*prev;
	t_dlst	*next;

	if (node)
	{
		prev = node->prev;
		next = node->next;
		if (del_content)
			del_content(node->content);
		if (del_node)
			del_node(node);
		else
			prev->next = next;
		if (next)
			next->prev = prev;
	}
}
