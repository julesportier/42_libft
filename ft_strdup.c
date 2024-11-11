/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:47:12 by juportie          #+#    #+#             */
/*   Updated: 2024/11/11 12:51:38 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	size_t	i;
	char	*mem;

	i = 0;
	s_len = ft_strlen(s);
	mem = malloc((s_len + 1) * sizeof(char));
	if (mem == NULL)
		return (NULL);
	while (i <= s_len)
	{
		mem[i] = s[i];
		i++;
	}
	return (mem);
}
