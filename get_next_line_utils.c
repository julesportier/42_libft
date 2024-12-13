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

static void	update_ret_len(char *s, struct s_static_data *data, ssize_t *len)
{
	if (data->malloc_error == -1)
	{
		*len = data->ret_len;
		if (s == NULL)
		{
			if (data->nl_pos == -1)
				data->ret_len = data->read_ret - data->start;
			else
				data->ret_len = data->nl_pos - data->start;
		}
		else
		{
			if (data->nl_pos == -1)
				data->ret_len += data->read_ret - data->start;
			else
				data->ret_len += data->nl_pos - data->start;
		}
	}
	else
	{
		*len = data->malloc_error;
		data->malloc_error = -1;
	}
}

static char	*malloc_cat(struct s_static_data *data, ssize_t line_len)
{
	char	*cat;

	if (data->read_ret > 0)
	{
		//DEBUG
		//static ssize_t i;
		//if(i++ == 0)
		//	cat = NULL;
		//else
		//END DEBUG
		cat = malloc(sizeof(char) * (data->ret_len + 1));
		if (cat == NULL)
			data->malloc_error = line_len;
	}
	else
	{
		cat = NULL;
		data->read_ret = BUFFER_SIZE;
		data->nl_pos = -1;
	}
	return (cat);
}

char	*ft_cat(char *line, struct s_static_data *data)
{
	ssize_t	line_len;
	char	*cat;
	ssize_t	i;

	update_ret_len(line, data, &line_len);
	cat = malloc_cat(data, line_len);
	if (cat == NULL)
	{
		free(line);
		return (NULL);
	}
	i = -1;
	while (++i < line_len)
		cat[i] = line[i];
	free(line);
	while (i < data->ret_len)
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
