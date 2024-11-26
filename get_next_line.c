/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:18:21 by juportie          #+#    #+#             */
/*   Updated: 2024/11/26 10:57:16 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*get_next_line(int fd)
{
	int	char_read;
	ssize_t	line_len;
	char	*buffer;

	if (!fd)
		return (NULL);
	line_len = 0;
	buffer = cat_line(line_len, NULL);
	if (buffer == NULL)
		return (NULL);
	while (buffer[line_len] != '\n')
	{
		buffer = cat_line(line_len, buffer);
		if (buffer == NULL)
			return (NULL);
		char_read = read(fd, buffer[line_len], 1);
		if (char_read == 0)
			return (buffer);
		else if (char_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		line_len += char_read;
	}
	return (buffer);
}
