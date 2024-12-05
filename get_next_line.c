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

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	static ssize_t	nl_pos = -1;
	static ssize_t	read_len = BUFFER_SIZE;
	char			*line;

	if (fd < 0)
		return (NULL);
	line = NULL;
	if (read_len < BUFFER_SIZE && nl_pos == -1)
		return (NULL);
	if (nl_pos <= BUFFER_SIZE && nl_pos >= 0)
	{
		line = ft_cat(
			line,
			buffer + nl_pos,
			get_line_len(buffer + nl_pos, BUFFER_SIZE - nl_pos)
		);
		if (nl_pos != -1 && get_line_len(buffer + nl_pos, BUFFER_SIZE - nl_pos) != -1)
			nl_pos += get_line_len(buffer + nl_pos, BUFFER_SIZE - nl_pos);
		else if (nl_pos != -1 && get_line_len(buffer + nl_pos, BUFFER_SIZE - nl_pos) == -1)
			nl_pos = -1;
		else
			nl_pos = get_line_len(buffer, BUFFER_SIZE);
		if (nl_pos <= BUFFER_SIZE && nl_pos >= 0)
		{
			if (nl_pos == BUFFER_SIZE || nl_pos == read_len)
				nl_pos = -1;
			return (line);
		}
		//nl_pos = -1;
	}
	while (nl_pos == -1)
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		if (read_len == 0)
			return (line);
		if (read_len == -1)
		{
			free(line);
			return (NULL);
		}
		nl_pos = get_line_len(buffer, read_len);
		line = ft_cat(line, buffer, nl_pos);
		if (nl_pos <= BUFFER_SIZE && nl_pos >= 0)
		{
			if (nl_pos == BUFFER_SIZE || nl_pos == read_len)
				nl_pos = -1;
			return (line);
		}
	}
	return (line);
}

#include <fcntl.h>
int	main(void)
//int	main(int argc, char *argv[])
{
//	if (argc)
	//int	fd = open("lorem_ipsum.txt", O_RDONLY);
	//int	fd = open("void.txt", O_RDONLY);
	//int	fd = open("nonewline.txt", O_RDONLY);
	//int	fd = open("bible.txt", O_RDONLY);
	int	fd = open("alarecherchedutempsperdu.txt", O_RDONLY);
	ssize_t	i = 0;
	char	*line;
	//char	*str = malloc(10);
	//read(fd, str, 10);
	//write(1, str, 10);
	printf("BUFFER_SIZE=%d\n", BUFFER_SIZE);
	while (i++ < 10850)
	{
		line = get_next_line(fd);
		printf("GNL %zu: %s", i, line);
		free(line);
	}
	return (0);
}
