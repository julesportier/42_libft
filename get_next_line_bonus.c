/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:53:08 by juportie          #+#    #+#             */
/*   Updated: 2024/12/12 17:31:24 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	line_is_filled(struct s_static_data *data, int fd)
{
	if (
		(data->nl_pos)[fd] <= (data->read_ret)[fd]
		&& (data->nl_pos)[fd] >= 0
	)
	{
		if ((data->nl_pos)[fd] == (data->read_ret)[fd])
			(data->nl_pos)[fd] = -1;
		return (1);
	}
	return (0);
}

static void	update_data_positions(struct s_static_data *data, int fd)
{
	if ((data->nl_pos)[fd] == -1)
		(data->start)[fd] = 0;
	else
		(data->start)[fd] = (data->nl_pos)[fd];
	(data->nl_pos)[fd] = get_line_len(
			(data->buffer)[fd] + (data->start)[fd],
			(data->read_ret)[fd] - (data->start)[fd]
			);
	if ((data->nl_pos)[fd] != -1)
		(data->nl_pos)[fd] += (data->start)[fd];
}

static char	*read_to_buffer(struct s_static_data *data, int fd, char **line)
{
	while ((data->nl_pos)[fd] == -1)
	{
		(data->read_ret)[fd] = read(fd, (data->buffer)[fd], BUFFER_SIZE);
		if ((data->read_ret)[fd] <= 0)
		{
			if ((data->read_ret)[fd] == -1)
			{
				free(*line);
				*line = NULL;
			}
			(data->read_ret)[fd] = BUFFER_SIZE;
			(data->nl_pos)[fd] = -1;
			(data->start)[fd] = 0;
			return (*line);
		}
		update_data_positions(data, fd);
		*line = ft_cat(*line, data, fd);
		if (line_is_filled(data, fd))
			return (*line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static struct s_static_data	data;
	char						*line;

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if ((data.start)[fd] == 0 && (data.nl_pos)[fd] == 0)
	{
		(data.nl_pos)[fd] = -1;
		(data.read_ret)[fd] = BUFFER_SIZE;
	}
	line = NULL;
	if ((data.nl_pos)[fd] <= (data.read_ret)[fd] && (data.nl_pos)[fd] >= 0)
	{
		update_data_positions(&data, fd);
		line = ft_cat(line, &data, fd);
		if (line_is_filled(&data, fd))
			return (line);
	}
	if ((data.read_ret)[fd] == BUFFER_SIZE && (data.nl_pos)[fd] == -1)
		return (read_to_buffer(&data, fd, &line));
	return (line);
}
