/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:41:10 by juportie          #+#    #+#             */
/*   Updated: 2024/12/12 17:47:34 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	update_ret_len(char *s, struct s_static_data *data)
{
	ssize_t	len;

	if (s == NULL)
	{
		len = 0;
		if (data->nl_pos == -1)
			data->ret_len = data->read_ret - data->start;
		else
			data->ret_len = data->nl_pos;
	}
	else
	{
		len = data->ret_len;
		if (data->nl_pos == -1)
			data->ret_len += data->read_ret - data->start;
		else
			data->ret_len += data->nl_pos;
	}
	return (len);
}

static char	*malloc_cat(
	struct s_static_data *data, ssize_t line_len, ssize_t *len
)
{
	char	*cat;

	if (data->nl_pos == -1)
		*len = data->read_ret - data->start;
	else
		*len = data->nl_pos - data->start;
	cat = malloc(sizeof(char) * (line_len + *len + 1));
	return (cat);
}

char	*ft_cat(char *line, struct s_static_data *data)
{
	ssize_t	line_len;
	char	*cat;
	ssize_t	i;
	ssize_t	len;

	line_len = update_ret_len(line, data);
	cat = malloc_cat(data, line_len, &len);
	if (cat == NULL)
	{
		data->read_ret = BUFFER_SIZE;
		data->nl_pos = -1;
		free(line);
		return (NULL);
	}
	i = -1;
	while (++i < line_len)
		cat[i] = line[i];
	free(line);
	while (i < line_len + len)
	{
		cat[i] = (data->buffer)[i - line_len + data->start];
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
