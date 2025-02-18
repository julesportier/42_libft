/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:32:31 by juportie          #+#    #+#             */
/*   Updated: 2024/12/16 19:11:18 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_buffer(char *buffer, int fd, char *line, ssize_t read_ret)
{
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
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		read_ret;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	line = NULL;
	read_ret = 0;
	if (buffer[0])
	{
		line = ft_cat(line, buffer);
		if (line_is_filled(line) || line == NULL)
			return (line);
	}
	if (!buffer[0])
	{
		return (fill_buffer(buffer, fd, line, read_ret));
	}
	return (line);
}
//
//#include <stdio.h>
//#include <fcntl.h>
//int	main(void)
//{
//	int	fd = open("giant_line_nl.txt", O_RDONLY);
//	ssize_t	i = 0;
//	char	*line = NULL;
//
//	while (i < 3)
//	{
//		line = get_next_line(fd);
//		printf("<|%s|>", line);
//		free(line);
//		i++;
//	}
//	return (0);
//}
//
//#include <stdio.h>
//#include <fcntl.h>
//int	main(void)
//{
//	int	fd = open("alarecherchedutempsperdu.txt", O_RDONLY);
//	ssize_t	i = 0;
//	char	*line = NULL;
//
//	while (i < 10850)
//	{
//		line = get_next_line(fd);
//		printf("<|%s|>", line);
//		free(line);
//		i++;
//	}
//	return (0);
//}
