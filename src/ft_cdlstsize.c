/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlstsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:02:14 by juportie          #+#    #+#             */
/*   Updated: 2025/03/14 16:03:49 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cdlstsize(t_dlst *lst)
{
	t_dlst	*head;
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
