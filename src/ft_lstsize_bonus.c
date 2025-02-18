/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:02:44 by juportie          #+#    #+#             */
/*   Updated: 2024/11/15 16:56:01 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
//
//#include <stdio.h>
//void	print_node(t_list *node, char *name)
//{
//	printf(":::::::::::::::::::::::::::::\n");
//	printf("%s->content == %s\n", name, (char *)(node->content));
//	printf("%s->address == %p\n", name, node);
//	if (node->next)
//		printf("%s->next == %p\n", name, node->next);
//	else
//		printf("%s->next == NULL\n", name);
//}
//
//void	print_list(t_list *node)
//{
//	while (node->next)
//	{
//		print_node(node, node->content);
//		node = node->next;
//	}
//	print_node(node, "NULL");
//}
//
//t_list	*create_list(int size)
//{
//	int	i;
//	t_list	*node;
//	t_list	*previous_node;
//
//	if (size < 1)
//		return (NULL);
//	node = ft_lstnew(ft_strdup("0"));
//	i = 1;
//	while (i < size)
//	{
//		previous_node = ft_lstnew(ft_itoa(i));
//		ft_lstadd_front(&node, previous_node);
//		node = previous_node;
//		i++;
//	}
//	return (node);
//}
//
//int	main(void)
//{
//	t_list	*list = create_list(9);
//	if (list == NULL)
//		return (-1);
//	//print_node(list, "list");
//	//print_node(list->next, "next");
//	print_list(list);
//	printf("list len == %d\n", ft_lstsize(list));
//	return (0);
//}
