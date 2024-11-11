/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:00:17 by juportie          #+#    #+#             */
/*   Updated: 2024/11/11 13:04:54 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*mem;

	i = 0;
	j = start;
	mem = malloc((len + 1) * sizeof(char));
	if (mem == NULL)
		return (NULL);
	while (i < len && s[j])
	{
		mem[i] = s[j];
		i++;
		j++;
	}
	mem[i] = '\0';
	return (mem);
}
