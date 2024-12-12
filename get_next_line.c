/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:18:21 by juportie          #+#    #+#             */
/*   Updated: 2024/12/12 18:01:55 by juportie         ###   ########.fr       */
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
