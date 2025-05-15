/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:47:12 by juportie          #+#    #+#             */
/*   Updated: 2025/05/15 08:52:26 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_s(const char *s)
{
	size_t	s_len;
	size_t	i;
	char	*mem;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	mem = malloc((s_len + 1) * sizeof(char));
	if (mem == NULL)
		return (NULL);
	i = 0;
	while (i <= s_len)
	{
		mem[i] = s[i];
		i++;
	}
	return (mem);
}
