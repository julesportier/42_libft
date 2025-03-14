/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlstclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:57:26 by juportie          #+#    #+#             */
/*   Updated: 2025/03/14 15:59:18 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cdlstclear(t_dlst **lst)
{
	t_dlst	*node;
	t_dlst	*tail;

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
