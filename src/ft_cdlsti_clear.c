/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlsti_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:25:19 by juportie          #+#    #+#             */
/*   Updated: 2025/02/22 12:57:05 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cdlsti_clear(t_dlisti **lst)
{
	t_dlisti	*node;
	t_dlisti	*tail;

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
		free(node);
	}
}
