/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:21:30 by juportie          #+#    #+#             */
/*   Updated: 2025/03/17 17:06:32 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_back(t_dlst **lst, t_dlst *new_node)
{
	t_dlst	*last;

	if (new_node && lst)
	{
		if (*lst)
		{
			last = ft_dlstlast(*lst);
			new_node->prev = last;
			last->next = new_node;
		}
		else
			*lst = new_node;
	}
}
