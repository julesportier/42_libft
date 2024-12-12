/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:57:37 by juportie          #+#    #+#             */
/*   Updated: 2024/12/12 17:31:55 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static ssize_t	update_ret_len(char *s, struct s_static_data *data, int fd)
{
	ssize_t	len;

	if (s == NULL)
	{
		len = 0;
		if ((data->nl_pos)[fd] == -1)
			(data->ret_len)[fd] = (data->read_ret)[fd] - (data->start)[fd];
		else
			(data->ret_len)[fd] = (data->nl_pos)[fd];
	}
	else
	{
		len = (data->ret_len)[fd];
		if ((data->nl_pos)[fd] == -1)
			(data->ret_len)[fd] += (data->read_ret)[fd] - (data->start)[fd];
		else
			(data->ret_len)[fd] += (data->nl_pos)[fd];
	}
	return (len);
}

static char	*malloc_cat(
	struct s_static_data *data, ssize_t line_len, ssize_t *len, int fd
)
{
	char	*cat;

	if ((data->nl_pos)[fd] == -1)
		*len = (data->read_ret)[fd] - (data->start)[fd];
	else
		*len = (data->nl_pos)[fd] - (data->start)[fd];
	cat = malloc(sizeof(char) * (line_len + *len + 1));
	return (cat);
}

char	*ft_cat(char *line, struct s_static_data *data, int fd)
{
	ssize_t	line_len;
	char	*cat;
	ssize_t	i;
	ssize_t	len;

	line_len = update_ret_len(line, data, fd);
	cat = malloc_cat(data, line_len, &len, fd);
	if (cat == NULL)
	{
		(data->read_ret)[fd] = BUFFER_SIZE;
		(data->nl_pos)[fd] = -1;
		free(line);
		return (NULL);
	}
	i = -1;
	while (++i < line_len)
		cat[i] = line[i];
	free(line);
	while (i < line_len + len)
	{
		cat[i] = (data->buffer)[fd][i - line_len + (data->start)[fd]];
		i++;
	}
	cat[i] = '\0';
	return (cat);
}

// The argument max_len is here to secure the reading,
// because neither the buffer or the file are true strings.
// The file can contain '\0' too (but why doing that ?).
ssize_t	get_line_len(char *buffer, ssize_t max_len)
{
	ssize_t	i;

	i = 0;
	while (i < max_len)
	{
		i++;
		if (buffer[i - 1] == '\n')
			return (i);
	}
	return (-1);
}
