/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:46:15 by juportie          #+#    #+#             */
/*   Updated: 2024/12/17 09:46:21 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static ssize_t	ft_len(char *str)
{
	ssize_t	i;

	i = 0;
	if (str)
	{
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			i++;
	}
	return (i);
}

void	shift_buffer(char *buffer, ssize_t buffer_len)
{
	ssize_t	i;

	i = 0;
	while (buffer[i + buffer_len])
	{
		buffer[i] = buffer[i + buffer_len];
		i++;
	}
	buffer[i] = '\0';
}

char	*ft_cat(char *line, char *buffer)
{
	ssize_t	line_len;
	ssize_t	buffer_len;
	ssize_t	i;
	char	*cat;

	line_len = ft_len(line);
	buffer_len = ft_len(buffer);
	cat = malloc(sizeof(char) * (line_len + buffer_len + 1));
	if (cat == NULL)
	{
		free(line);
		return (NULL);
	}
	i = -1;
	while (++i < line_len)
		cat[i] = line[i];
	free(line);
	while (i < line_len + buffer_len)
	{
		cat[i] = buffer[i - line_len];
		i++;
	}
	cat[i] = '\0';
	shift_buffer(buffer, buffer_len);
	return (cat);
}

ssize_t	line_is_filled(char *line)
{
	ssize_t	i;

	i = 0;
	if (line)
	{
		while (line[i])
		{
			if (line[i] == '\n')
				return (1);
			i++;
		}
	}
	return (0);
}
