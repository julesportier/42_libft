/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:48:53 by juportie          #+#    #+#             */
/*   Updated: 2025/05/07 09:57:00 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Pointers to the original list and to the new "list_b" head must be kept
// before calling this function.
void	ft_dlstsplit(t_dlst *lst_b_head)
{
	if (lst_b_head
		&& lst_b_head->prev != NULL)
	{
		lst_b_head->prev->next = NULL;
		lst_b_head->prev = NULL;
	}
}
