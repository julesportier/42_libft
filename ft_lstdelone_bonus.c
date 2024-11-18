/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:36:42 by juportie          #+#    #+#             */
/*   Updated: 2024/11/18 12:25:29 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	del(lst -> content);
	free(lst);
}
//
//#include <stdio.h>
//void	print_node(t_list *node, char *name)
//{
//	printf(":::::::::::::::::::::::::::::\n");
//	if (node)
//	{
//		if (node -> content)
//			printf("%s -> content == %s\n", name, (char *)(node -> content));
//		else
//			printf("%s -> content == NULL\n", name);
//		printf("%s -> address == %p\n", name, node);
//		if (node -> next)
//			printf("%s -> next == %p\n", name, node -> next);
//		else
//			printf("%s -> next == NULL\n", name);
//	}
//	else
//		printf("%s == NULL\n", name);
//}
//
//void	print_list(t_list *node)
//{
//	while (node -> next)
//	{
//		print_node(node, node -> content);
//		node = node -> next;
//	}
//	print_node(node, node -> content);
//}
//
//t_list	*create_list(int size)
//{
//	t_list	*node;
//	t_list	*previous_node;
//
//	if (size < 1)
//		return (NULL);
//	node = ft_lstnew(ft_itoa(size - 1));
//	while (--size)
//	{
//		previous_node = ft_lstnew(ft_itoa(size - 1));
//		ft_lstadd_front(&node, previous_node);
//		node = previous_node;
//	}
//	return (node);
//}
//
//// need lst_del inner free to be commented and content to be a string
//void	test_del(void *content)
//{
//	*(char **)content = content;
//}
//int	main(void)
//{
//	t_list	*list;
//	t_list	*node_to_del;
//	t_list	*next_node;
//
//	list = create_list(5);
//	if (list == NULL)
//		return (-1);
//	node_to_del = list -> next;
//	next_node = node_to_del -> next;
//	print_list(list);
//	//ft_lstdelone(node_to_del, test_del);
//	ft_lstdelone(node_to_del, free);
//	print_node(list, "before deleted");
//	print_node(next_node, "after deleted");
//	print_list(list);
//	return (0);
//}
