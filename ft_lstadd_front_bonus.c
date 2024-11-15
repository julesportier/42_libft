/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:33:16 by juportie          #+#    #+#             */
/*   Updated: 2024/11/15 13:58:55 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
}
//
//#include <stdio.h>
//void	print_node(t_list *node, char *name)
//{
//	printf(":::::::::::::::::::::::::::::\n");
//	printf("%s -> content == %s\n", name, (char *)(node -> content));
//	printf("%s -> address == %p\n", name, node);
//	if (node -> next)
//		printf("%s -> next == %p\n", name, node -> next);
//	else
//		printf("%s -> next == NULL\n", name);
//}
//
//int	main(void)
//{
//	t_list	*node = ft_lstnew("test");
//	t_list	*new_node = ft_lstnew("add");
//	print_node(node, "node");
//	print_node(new_node, "new_node");
//
//	t_list	**first_node = &node;
//	ft_lstadd_front(first_node, new_node);
//	print_node(new_node, "new_node");
//
//	free(node);
//	node = NULL;
//	free(new_node);
//	new_node = NULL;
//	return (0);
//}
