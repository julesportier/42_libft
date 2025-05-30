/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlsthead.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:02:21 by juportie          #+#    #+#             */
/*   Updated: 2025/03/19 11:02:55 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlst	*ft_dlsthead(t_dlst *lst)
{
	if (lst)
	{
		while (lst->prev)
			lst = lst->prev;
	}
	return (lst);
}
