/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:27:31 by juportie          #+#    #+#             */
/*   Updated: 2024/11/13 12:07:16 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = dst_len;
	if (size < dst_len)
		return (src_len + size);
	while (i + 1 < size && i < (src_len + dst_len))
	{
		dst[i] = src[i - dst_len];
		i++;
	}
	dst[i] = '\0';
	return (src_len + dst_len);
}
