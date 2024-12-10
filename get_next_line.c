/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:18:21 by juportie          #+#    #+#             */
/*   Updated: 2024/12/06 15:04:45 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	line_is_filled(struct s_static_data *data)
{
	if (
		data->nl_pos <= BUFFER_SIZE + 1
		&& data->nl_pos >= 0
	)
	{
		if (
			data->nl_pos == BUFFER_SIZE + 1
			|| data->nl_pos == data->read_ret
		)
			data->nl_pos = -1;
		return (1);
	}
	return (0);
}

static char	*append_to_line(struct s_static_data *data, char *line)
{
	line = ft_cat(line, data->buffer, data->nl_pos);
	if (data->nl_pos == -1)
		data->start = 0;
	else
		data->start = data->nl_pos;
	data->nl_pos = get_line_len(
			data->buffer + data->start,
			BUFFER_SIZE - data->start
			);
	if (data->nl_pos != -1)
		data->nl_pos += data->start;
	return (line);
}

static char	*read_to_buffer(struct s_static_data *data, int fd, char **line)
{
	while (data->nl_pos == -1)
	{
		data->read_ret = read(fd, data->buffer, BUFFER_SIZE);
		if (data->read_ret == -1)
		{
			free(*line);
			return (NULL);
		}
		else if (data->read_ret == 0)
			return (*line);
		*line = append_to_line(data, *line);
		if (line_is_filled(data))
			return (*line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static struct s_static_data	data = {
		.start = 0, .nl_pos = -1, .read_ret = BUFFER_SIZE
	};
	char						*line;

	if (fd < 0)
		return (NULL);
	line = NULL;
	if (data.read_ret < BUFFER_SIZE && data.nl_pos == -1)
		return (NULL);
	if (data.nl_pos <= BUFFER_SIZE && data.nl_pos >= 0)
	{
		line = append_to_line(&data, line);
		if (line_is_filled(&data))
			return (line);
	}
	if (data.nl_pos == -1)
		return (read_to_buffer(&data, fd, &line));
	return (line);
}

#include <stdio.h>
#include <fcntl.h>
int	main(void)
//int	main(int argc, char *argv[])
{
//	if (argc)
	//int	fd = open("lorem_ipsum.txt", O_RDONLY);
	//int	fd = open("void.txt", O_RDONLY);
	int	fd = open("nonewline.txt", O_RDONLY);
	//int	fd = open("bible.txt", O_RDONLY);
	//int	fd = open("alarecherchedutempsperdu.txt", O_RDONLY);
	ssize_t	i = 0;
	char	*line;
	//char	*str = malloc(10);
	//read(fd, str, 10);
	//write(1, str, 10);
	printf("BUFFER_SIZE=%d\n", BUFFER_SIZE);
	while (i++ < 1)
	{
		line = get_next_line(fd);
		printf("GNL %zu: %s", i, line);
		free(line);
	}
	return (0);
}
