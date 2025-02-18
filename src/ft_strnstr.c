/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:18:55 by juportie          #+#    #+#             */
/*   Updated: 2024/11/08 15:24:28 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;
	char	*little_start;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	i = 0;
	little_start = NULL;
	while (i < len && big[i])
	{
		if (little[0] == big[i])
		{
			little_start = &((char *)big)[i];
			if (
				ft_strncmp(&big[i], little, little_len) == 0
				&& i + little_len <= len
			)
				return (little_start);
		}
		i++;
	}
	return (NULL);
}
