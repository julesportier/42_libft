/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:31:21 by juportie          #+#    #+#             */
/*   Updated: 2025/03/17 16:33:35 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstclear(t_dlst *lst)
{
	t_dlst	*node;

	while (lst)
	{
		node = lst;
		lst = node->next;
		free(node->content);
		node->content = NULL;
		free(node);
		node = NULL;
	}
}
