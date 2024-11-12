/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:12:13 by juportie          #+#    #+#             */
/*   Updated: 2024/11/12 13:14:13 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	count_splits(char const *s, char c)
{
	size_t	i;
	size_t	count;
	int		in_sep;

	i = 0;
	count = 1;
	while (s[i])
	{
		in_sep = 0;
		while (s[i] == c)
		{
			if (in_sep == 0)
			{
				count++;
				in_sep = 1;
			}
			else
				i++;
		}
		i++;
	}
	printf("count = %zu\n", count);
	return (count);
}

size_t	get_split_len(char const *s, char c, size_t start)
{
	size_t	i;

	i = 0;
	while (s[i + start])
	{
		if (s[i + start] == c)
			return (i);
		i++;
	}
	return (i);
}

char	*make_split(char const *s, char c, size_t start)
{
	size_t	split_len;
	char	*split;
	size_t	i;

	split_len = get_split_len(s, c, start);
	split = malloc((split_len + 1) * sizeof(char));
	if (split == NULL)
		return (NULL);
	i = 0;
	while (i < split_len)
	{
		split[i] = s[start + i];
		i++;
	}
	split[i] = '\0';
	return (split);
}

char	**free_splits(char **array, size_t pos)
{
	while (pos)
	{
		free(array[pos]);
		array[pos] = NULL;
		pos--;
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	array_size;
	char	**array;
	size_t	array_pos;
	size_t	s_pos;
	size_t	split_len;

	array_size = count_splits(s, c) + 1;
	array = malloc(array_size * sizeof(char *));
	array_pos = 0;
	s_pos = 0;
	while (array_pos < array_size - 1)
	{
		split_len = get_split_len(s, c, s_pos);
		array[array_pos] = make_split(s, c, s_pos);
		if (array[array_pos] == NULL)
			return (free_splits(array, array_pos));
		s_pos = s_pos + split_len + 1;
		while (s[s_pos] == c)
			s_pos++;
		array_pos++;
	}
	array[array_pos] = NULL;
	return (array);
}
