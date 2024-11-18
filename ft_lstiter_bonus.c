/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:48:28 by juportie          #+#    #+#             */
/*   Updated: 2024/11/18 18:27:17 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL)
		return ;
	while (lst -> next)
	{
		f(lst -> content);
		lst = lst -> next;
	}
	f(lst -> content);
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
//void	change_node_content(void *content)
//{
//	if (content != NULL)
//	{
//		*(char *)content = 'c';
//	}
//}
//
//void	del_node_content(void *content)
//{
//	if (content != NULL)
//		free(content);
//}
//
//int	main(void)
//{
//	t_list	*list;
//
//	list = create_list(15);
//	if (list == NULL)
//		return (-1);
//	print_list(list);
//	ft_lstiter(list, change_node_content);
//	print_list(list);
//	ft_lstclear(&list, del_node_content);
//	list = NULL;
//	return (0);
//}
