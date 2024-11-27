/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:41:10 by juportie          #+#    #+#             */
/*   Updated: 2024/11/28 13:14:49 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	ft_strlen(char *s)
{
	ssize_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_cat(char *line, char *buffer, ssize_t len)
{
	ssize_t	line_len;
	char	*cat;
	ssize_t	i;

	line_len = ft_strlen(line);
	cat = malloc(sizeof(char) * (line_len + len + 1));
	if (cat == NULL)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (i < line_len)
	{
		cat[i] = line[i];
		i++;
	}
	free(line);
	while (i < line_len + len)
	{
		cat[i] = buffer[i - line_len];
		i++;
	}
	cat[i] = '\0';
	return (cat);
}

//ssize_t	fill_buffer(char *buffer)
//{
//	return (read(fd, buffer, BUFFER_SIZE));
//}

// The argument max_len is here to secure the reading,
// because neither the buffer or the file are true strings.
// The file can contain '\0' too (but why doing that ?).
ssize_t	get_line_len(char *buffer, ssize_t max_len)
{
	ssize_t	i;

	i = 0;
	while (i < max_len)
	{
		i++;
 		if (buffer[i] == '\n')
			return (i);
	}
	return (i);
}
