/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:23:00 by juportie          #+#    #+#             */
/*   Updated: 2024/11/13 09:39:06 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char const *set, char const c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*mem;

	start = 0;
	while (in_set(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	if (end > 0)
		end--;
	while (in_set(set, s1[end]))
		end--;
	if (end - start < 0)
		return (NULL);
	mem = malloc((end - start + 2) * sizeof(char));
	if (mem == NULL)
		return (NULL);
	i = 0;
	while ((start + i++) <= end)
		mem[i - 1] = s1[start + i - 1];
	mem[i] = '\0';
	return (mem);
}
