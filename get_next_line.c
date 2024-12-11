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
		data->nl_pos <= data->read_ret
		&& data->nl_pos >= 0
	)
	{
		if (data->nl_pos == data->read_ret)
			data->nl_pos = -1;
		return (1);
	}
	return (0);
}

void	update_data_positions(struct s_static_data *data)
{
	if (data->nl_pos == -1)
		data->start = 0;
	else
		data->start = data->nl_pos;
	data->nl_pos = get_line_len(
			data->buffer + data->start,
			data->read_ret - data->start
			);
	if (data->nl_pos != -1)
		data->nl_pos += data->start;
}

static char	*read_to_buffer(struct s_static_data *data, int fd, char **line)
{
	while (data->nl_pos == -1)
	{
		data->read_ret = read(fd, data->buffer, BUFFER_SIZE);
		if (data->read_ret <= 0)
		{
			if (data->read_ret == -1)
			{
				free(*line);
				*line = NULL;
			}
			data->read_ret = BUFFER_SIZE;
			data->nl_pos = -1;
			data->start = 0;
			return (*line);
		}
		update_data_positions(data);
		*line = ft_cat(*line, data);
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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (data.nl_pos <= data.read_ret && data.nl_pos >= 0)
	{
		update_data_positions(&data);
		line = ft_cat(line, &data);
		if (line_is_filled(&data))
			return (line);
	}
	if (data.read_ret == BUFFER_SIZE && data.nl_pos == -1)
		return (read_to_buffer(&data, fd, &line));
	return (line);
}
// BASIC MAIN
//#include <stdio.h>
//#include <fcntl.h>
//int	main(void)
//{
//	int	fd = open("lorem_ipsum.txt", O_RDONLY);
//	//int	fd = open("multiple_lines_no_nl.txt", O_RDONLY);
//	//int	fd = open("void.txt", O_RDONLY);
//	//int	fd = open("nonewline.txt", O_RDONLY);
//	//int	fd = open("bible.txt", O_RDONLY);
//	//int	fd = open("alarecherchedutempsperdu.txt", O_RDONLY);
//	size_t	i = 0;
//	char	*line;
//
//	printf("BUFFER_SIZE=%d\n", BUFFER_SIZE);
//	while (i++ < 18)
//	{
//		line = get_next_line(fd);
//		printf("GNL%zu: %s", i, line);
//		free(line);
//	}
//	close(fd);
//	return (0);
//}
// MAIN FOR READ_ERROR
// ADD THIS LINES INTO READ_TO_BUFFER()
	//DEBUG
	//static int	i;
	//if (i++ == 2)
	//	data->read_ret = -1;
	//END DEBUG
//#include <stdio.h>
//#include <fcntl.h>
//int	main(void)
//{
//	int	fd;
//	size_t	i = 0;
//	char	*line;
//
//	printf("BUFFER_SIZE=%d\n", BUFFER_SIZE);
//	fd = open("read_error.txt", O_RDONLY);
//	// COMPARISON MUST BE CONSISTENT WITH TRIGGERED READ ERROR
//	while (i++ < 2)
//	{
//		line = get_next_line(fd);
//		printf("GNL(fd1)%zu: %s", i, line);
//		free(line);
//	}
//	close(fd);
//	fd = open("read_error.txt", O_RDONLY);
//	while (i < 8)
//	{
//		line = get_next_line(fd);
//		printf("GNL(fd2)%zu: %s", i, line);
//		free(line);
//		i++;
//	}
//	close(fd);
//	return (0);
//}
// MAIN FOR USE WITH test.bash
// THE SCRIPT CREATE THE FILE
//#include <stdio.h>
//#include <fcntl.h>
//int	main(void)
//{
//	int	fd;
//	size_t	i = 0;
//	char	*line;
//
//	fd = open("test.txt", O_RDONLY);
//	while (i++ < 3)
//	{
//		line = get_next_line(fd);
//		printf("GNL%zu: %s", i, line);
//		free(line);
//	}
//	close(fd);
//	return (0);
//}
