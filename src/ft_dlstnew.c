/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:04:25 by juportie          #+#    #+#             */
/*   Updated: 2025/02/26 12:38:40 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlst	*ft_dlstnew(void *content)
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
