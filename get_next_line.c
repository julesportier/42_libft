/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:18:21 by juportie          #+#    #+#             */
/*   Updated: 2024/11/28 13:18:11 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

	#include <stdio.h>
//char	*get_next_line(int fd)
//{
//	static char		buffer[BUFFER_SIZE];
//	static ssize_t	nl_pos = BUFFER_SIZE;
//	static ssize_t	read_len;
//	char			*line;
//
//	if (fd < 0)
//		return (NULL);
//	line = NULL;
//	if (nl_pos < BUFFER_SIZE)
//	{
//		line = ft_cat(
//			line,
//			buffer + nl_pos,
//			get_line_len(buffer + nl_pos, BUFFER_SIZE - nl_pos)
//		);
//		nl_pos += get_line_len(line, BUFFER_SIZE - nl_pos);
//	}
//	while (nl_pos == BUFFER_SIZE)
//	{
//		read_len = read(fd, buffer, BUFFER_SIZE);
//		if (read_len == -1)
//		{
//			free(line);
//			return (NULL);
//		}
//		nl_pos = get_line_len(buffer, read_len);
//		line = ft_cat(line, buffer, nl_pos);
//	}
//	return (line);
//}
char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	static ssize_t	nl_pos = BUFFER_SIZE;
	static ssize_t	read_len;
	char			*line;

	if (fd < 0)
		return (NULL);
	line = NULL;
	if (nl_pos < BUFFER_SIZE)
	{
		line = ft_cat(
			line,
			buffer + nl_pos,
			get_line_len(buffer + nl_pos, BUFFER_SIZE - nl_pos)
		);
		nl_pos += get_line_len(buffer + nl_pos, BUFFER_SIZE - nl_pos);
	}
	while (nl_pos == BUFFER_SIZE)
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		if (read_len == -1)
		{
			free(line);
			return (NULL);
		}
		nl_pos = get_line_len(buffer, read_len);
		line = ft_cat(line, buffer, nl_pos);
	}
	return (line);
}

#include <fcntl.h>
int	main(void)
//int	main(int argc, char *argv[])
{
//	if (argc)
	int	fd = open("lorem_ipsum.txt", O_RDONLY);
	ssize_t	i = 0;
	//char	*str = malloc(10);
	//read(fd, str, 10);
	//write(1, str, 10);
	while (i++ < 5)
		printf("%s", get_next_line(fd));
	return (0);
}
//char	*get_next_line(int fd)
//{
//	int	char_read;
//	ssize_t	line_len;
//	char	*buffer;
//
//	if (fd < 0)
//		return (NULL);
//	line_len = 0;
//	buffer = cat_line(line_len, NULL);
//	if (buffer == NULL)
//		return (NULL);
//	while (buffer[line_len] != '\n')
//	{
//		buffer = cat_line(line_len, buffer);
//		if (buffer == NULL)
//			return (NULL);
//		char_read = read(fd, buffer + line_len, 1);
//		if (char_read == 0)
//		{
//			buffer[line_len + 1] = '\0';
//			return (buffer);
//		}
//		else if (char_read == -1)
//		{
//			free(buffer);
//			return (NULL);
//		}
//		line_len += char_read;
//	}
//	return (buffer);
//}
