/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:12:13 by juportie          #+#    #+#             */
/*   Updated: 2024/11/15 10:52:16 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_splits(char const *s, char c)
{
	int		in_split;
	size_t	i;
	size_t	count;

	in_split = 0;
	count = 0;
	i = 0;
	while (s[i])
	{
		if (!in_split && s[i] != c)
		{
			in_split = 1;
			count++;
		}
		else if (in_split && s[i] == c)
			in_split = 0;
		i++;
	}
	return (count);
}

static size_t	get_split_len(char const *s, char c, size_t start)
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

static char	*make_split(char const *s, size_t start, size_t split_len)
{
	char	*split;
	size_t	i;

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

static char	**free_splits(char **array, size_t pos)
{
	size_t	i;

	i = 0;
	while (i < pos)
	{
		free(array[pos]);
		array[pos] = NULL;
		i++;
	}
	free(array);
	array = NULL;
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
	if (array == NULL)
		return (NULL);
	array_pos = 0;
	s_pos = 0;
	while (array_pos < array_size - 1)
	{
		while (s[s_pos] == c)
			s_pos++;
		split_len = get_split_len(s, c, s_pos);
		array[array_pos] = make_split(s, s_pos, split_len);
		if (array[array_pos] == NULL)
			return (free_splits(array, array_pos));
		s_pos = s_pos + split_len + 1;
		array_pos++;
	}
	array[array_pos] = NULL;
	return (array);
}
//
//#include <stdio.h>
//int	main(int argc, char *argv[])
//{
//	char	**splits;
//	size_t	i;
//
//	if (argc == 3)
//	{
//		splits = ft_split(argv[1], argv[2][0]);
//		i = 0;
//		while (splits[i])
//		{
//			printf("splits[%zu]: %s\n", i, splits[i]);
//			free(splits[i]);
//			splits[i] = NULL;
//			i++;
//		}
//		free(splits);
//		splits = NULL;
//		return (0);
//	}
//	printf("two args required\n");
//	return (-1);
//}
