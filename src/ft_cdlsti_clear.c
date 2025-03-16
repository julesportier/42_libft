/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlsti_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:25:19 by juportie          #+#    #+#             */
/*   Updated: 2025/02/26 12:39:09 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cdlsti_clear(t_dlsti **lst)
{
	t_dlsti	*node;
	t_dlsti	*last;

	if (lst == NULL || *lst == NULL)
		return ;
	last = (*lst)->prev;
	while (*lst)
	{
		node = *lst;
		if (*lst != last)
			*lst = node->next;
		else
			*lst = NULL;
		free(node);
	}
}
