/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlsti_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:03:29 by juportie          #+#    #+#             */
/*   Updated: 2025/02/21 13:04:10 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cdlsti_add_back(t_dlisti **lst, t_dlisti *new_node)
{
	t_dlisti	*last;

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
