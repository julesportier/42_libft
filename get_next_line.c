/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:18:21 by juportie          #+#    #+#             */
/*   Updated: 2024/11/26 10:38:28 by juportie         ###   ########.fr       */
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
	while (buffer[lin_len] != '\n')
	{
		buffer = malloc(sizeof(char) * (line_len + 1);
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
