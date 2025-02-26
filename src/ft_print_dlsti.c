/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dlsti.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:04:58 by juportie          #+#    #+#             */
/*   Updated: 2025/02/26 12:39:28 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_printf.h"
#include "libft.h"

void	ft_print_dlsti(t_dlsti *lst)
{
	t_dlsti	*head;

	head = lst;
	while (lst)
	{
		ft_printf("node %X; next %X; prev %X; content %d\n",
			lst, lst->next, lst->prev, lst->content);
		if (lst->next == head)
			return ;
		lst = lst->next;
	}
}
