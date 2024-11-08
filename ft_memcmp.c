/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:30:20 by juportie          #+#    #+#             */
/*   Updated: 2024/11/08 14:14:56 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (
		((unsigned char *)s1)[i] == ((unsigned char *)s2)[i]
		&& i < (n - 1)
	)
		i++;
	return (((unsigned char *)s1)[i] - (((unsigned char *)s2)[i]));
}
