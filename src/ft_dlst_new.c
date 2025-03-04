/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 07:06:41 by juportie          #+#    #+#             */
/*   Updated: 2025/03/04 07:07:36 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlst	*ft_dlst_new(void *content)
{
	t_dlst	*lst;

	lst = malloc(sizeof(t_dlst));
	if (lst != NULL)
	{
		lst->content = content;
		lst->next = NULL;
		lst->prev = NULL;
	}
	return (lst);
}
