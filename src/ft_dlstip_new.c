/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstip_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 07:06:41 by juportie          #+#    #+#             */
/*   Updated: 2025/03/04 08:46:20 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlstip	*ft_dlstip_new(int *content)
{
	t_dlstip	*lst;

	lst = malloc(sizeof(t_dlstip));
	if (lst != NULL)
	{
		lst->content = content;
		lst->next = NULL;
		lst->prev = NULL;
	}
	return (lst);
}
