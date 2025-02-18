/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:08:14 by juportie          #+#    #+#             */
/*   Updated: 2024/11/15 13:43:00 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
//
//#include <stdio.h>
//int	main(void)
//{
//	char	*content = "test";
//	t_list	*list = ft_lstnew(content);
//
//	printf("list.content == %s\n", (char *)(list->content));
//	free(list);
//	list = NULL;
//	return (0);
//}
