/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlsti_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:03:30 by juportie          #+#    #+#             */
/*   Updated: 2025/02/26 10:10:50 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cdlsti_size(t_dlsti *lst)
{
	t_dlsti	*head;
	int		i;

	head = lst;
	i = 0;
	while (lst)
	{
		if (++i < 0)
			return (-1);
		lst = lst->next;
		if (lst == head)
			return (i);
	}
	return (i);
}
