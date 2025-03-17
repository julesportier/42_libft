/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:14:16 by juportie          #+#    #+#             */
/*   Updated: 2025/03/17 16:16:23 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_front(t_dlst **lst, t_dlst *new_node)
{
	if (new_node && lst)
	{
		new_node->next = *lst;
		if (*lst)
			(*lst)->prev = new_node;
		*lst = new_node;
	}
}
