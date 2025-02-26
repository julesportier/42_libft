/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlsti_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:04:25 by juportie          #+#    #+#             */
/*   Updated: 2025/02/26 12:38:40 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlsti	*ft_dlsti_new(int i)
{
	t_dlsti	*lst;

	lst = malloc(sizeof(t_dlsti));
	if (lst != NULL)
	{
		lst->content = i;
		lst->next = NULL;
		lst->prev = NULL;
	}
	return (lst);
}
