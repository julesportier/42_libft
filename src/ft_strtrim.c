/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:23:00 by juportie          #+#    #+#             */
/*   Updated: 2024/11/14 16:29:17 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_set(char const c, char const *set)
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

static size_t	get_trim_size(size_t start, size_t end)
{
	if (end <= start)
		return (0);
	else
		return (end - start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_pos;
	size_t	end;
	size_t	i;
	char	*s_trimmed;

	end = ft_strlen(s1);
	if (set[0] && end)
	{
		start_pos = 0;
		while (char_in_set(s1[start_pos], set))
			start_pos++;
		while (char_in_set(s1[end - 1], set))
			end--;
		s_trimmed = malloc((get_trim_size(start_pos, end) + 1) * sizeof(char));
		if (s_trimmed == NULL)
			return (NULL);
		i = 0;
		while (start_pos + i++ < end)
			s_trimmed[i - 1] = s1[start_pos + i - 1];
		s_trimmed[i - 1] = '\0';
		return (s_trimmed);
	}
	else
		return (ft_strdup(s1));
}
//
//int	main(void)
//{
//	char	*temp;
//
//	//temp = ft_strtrim("abcdba", "acb");
//	//temp = ft_strtrim("", "");
//	temp = ft_strtrim("abaab", "ab");
//	ft_putendl_fd(temp, 1);
//	free(temp);
//	temp = NULL;
//	return (0);
//}
