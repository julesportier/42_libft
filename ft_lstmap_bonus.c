/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:10:54 by juportie          #+#    #+#             */
/*   Updated: 2024/11/19 09:12:41 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_secured(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list == NULL)
	{
		free(content);
		return (NULL);
	}
	list -> content = content;
	list -> next = NULL;
	return (list);
}

static t_list	*map_node(t_list *lst, t_list **mapped_list, void *(*f)(void *))
{
	ft_lstadd_back(mapped_list, ft_lstnew_secured(f(lst -> content)));
	if ((*mapped_list)-> next)
		return ((*mapped_list)-> next);
	else
		return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped_list;
	t_list	*mapped_list_head;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	mapped_list = ft_lstnew_secured(f(lst -> content));
	if (mapped_list == NULL)
		return (NULL);
	mapped_list_head = mapped_list;
	while (lst -> next)
	{
		lst = lst -> next;
		mapped_list = map_node(lst, &mapped_list, f);
		if (mapped_list == NULL)
		{
			ft_lstclear(&mapped_list_head, del);
			return (NULL);
		}
	}
	return (mapped_list_head);
}
//
//#include <stdio.h>
//void	print_node(t_list *node, size_t node_id)
//{
//	printf(":::::::::::::::::::::::::::::\n");
//	if (node)
//	{
//		printf("%zu -> address == %p\n", node_id, node);
//		if (node -> content)
//			printf(
//				"%zu -> content == %s\n",
//				node_id, (char *)(node -> content)
//			);
//		else
//			printf("%zu -> content == NULL\n", node_id);
//		if (node -> next)
//			printf("%zu -> next == %p\n", node_id, node -> next);
//		else
//			printf("%zu -> next == NULL\n", node_id);
//	}
//	else
//		printf("%zu == NULL\n", node_id);
//}
//
//void	print_list(t_list *node)
//{
//	size_t	i;
//
//	i = 0;
//	while (node -> next)
//	{
//		print_node(node, i++);
//		node = node -> next;
//	}
//	print_node(node, i);
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
//void	*map_node_content(void *content)
//{
//	if (content != NULL)
//		return (ft_strjoin(content, "map"));
//	return (NULL);
//}
//
//void	free_node_content(void *content)
//{
//	if (content != NULL)
//		free(content);
//}
//
//int	main(void)
//{
//	t_list	*list;
//	t_list	*mapped_list;
//
//	list = create_list(15);
//	if (list == NULL)
//		return (-1);
//	printf("\nLIST :\n");
//	print_list(list);
//	mapped_list = ft_lstmap(list, map_node_content, free_node_content);
//	printf("\nMAPPED LIST :\n");
//	print_list(mapped_list);
//	printf("\nLIST :\n");
//	print_list(list);
//	ft_lstclear(&list, free_node_content);
//	list = NULL;
//	ft_lstclear(&mapped_list, free_node_content);
//	mapped_list = NULL;
//	return (0);
//}
