/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:46:25 by juportie          #+#    #+#             */
/*   Updated: 2024/12/17 10:18:26 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*fill_buffer(char *buffer, int fd, char *line)
{
	ssize_t		read_ret;

	read_ret = 0;
	while (!buffer[0])
	{
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret >= 0)
			buffer[read_ret] = '\0';
		else
			buffer[0] = '\0';
		if (read_ret <= 0)
		{
			if (read_ret == -1)
			{
				free(line);
				line = NULL;
			}
			return (line);
		}
		line = ft_cat(line, buffer);
		if (line_is_filled(line) || read_ret < BUFFER_SIZE || line == NULL)
			return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FD][BUFFER_SIZE + 1];
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > MAX_FD)
		return (NULL);
	line = NULL;
	if (buffer[fd][0])
	{
		line = ft_cat(line, buffer[fd]);
		if (line_is_filled(line) || line == NULL)
			return (line);
	}
	if (!buffer[fd][0])
	{
		return (fill_buffer(buffer[fd], fd, line));
	}
	return (line);
}
