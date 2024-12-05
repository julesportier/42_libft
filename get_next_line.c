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
	static struct static_data	data = {.nl_pos = -1, .read_len = BUFFER_SIZE};
	//static char		buffer[BUFFER_SIZE];
	//static ssize_t	nl_pos = -1;
	static ssize_t	read_len = BUFFER_SIZE;
	char			*line;

	if (fd < 0)
		return (NULL);
	//data.nl_pos = -1;
	//data.read_len = BU;
	line = NULL;
	if (read_len < BUFFER_SIZE && data.nl_pos == -1)
		return (NULL);
	if (data.nl_pos <= BUFFER_SIZE && data.nl_pos >= 0)
	{
		line = ft_cat(line, data.buffer, data.nl_pos);
		if (data.nl_pos != -1 && get_line_len(data.buffer + data.nl_pos, BUFFER_SIZE - data.nl_pos) != -1)
			data.nl_pos += get_line_len(data.buffer + data.nl_pos, BUFFER_SIZE - data.nl_pos);
		else if (data.nl_pos != -1 && get_line_len(data.buffer + data.nl_pos, BUFFER_SIZE - data.nl_pos) == -1)
			data.nl_pos = -1;
		else
			data.nl_pos = get_line_len(data.buffer, BUFFER_SIZE);
		if (data.nl_pos <= BUFFER_SIZE && data.nl_pos >= 0)
		{
			if (data.nl_pos == BUFFER_SIZE || data.nl_pos == read_len)
				data.nl_pos = -1;
			return (line);
		}
		//data.nl_pos = -1;
	}
	while (data.nl_pos == -1)
	{
		read_len = read(fd, data.buffer, BUFFER_SIZE);
		if (read_len == 0)
			return (line);
		if (read_len == -1)
		{
			free(line);
			return (NULL);
		}
		line = ft_cat(line, data.buffer, data.nl_pos);
		data.nl_pos = get_line_len(data.buffer, read_len);
		if (data.nl_pos <= BUFFER_SIZE && data.nl_pos >= 0)
		{
			if (data.nl_pos == BUFFER_SIZE || data.nl_pos == read_len)
				data.nl_pos = -1;
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
	int	fd = open("lorem_ipsum.txt", O_RDONLY);
	//int	fd = open("void.txt", O_RDONLY);
	//int	fd = open("nonewline.txt", O_RDONLY);
	//int	fd = open("bible.txt", O_RDONLY);
	//int	fd = open("alarecherchedutempsperdu.txt", O_RDONLY);
	ssize_t	i = 0;
	char	*line;
	//char	*str = malloc(10);
	//read(fd, str, 10);
	//write(1, str, 10);
	printf("BUFFER_SIZE=%d\n", BUFFER_SIZE);
	while (i++ < 50)
	{
		line = get_next_line(fd);
		printf("GNL %zu: %s", i, line);
		free(line);
	}
	return (0);
}
