/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:41:10 by juportie          #+#    #+#             */
/*   Updated: 2024/11/26 11:18:01 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*create_buffer(ssize_t line_len, char *buffer)
{
	char	*new_buffer;
	ssize_t	malloc_size;

	if (buffer)
		malloc_size = line_len + 1;
	else if (line_len == 0)
		malloc_size = 1;
	else
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = malloc(sizeof(char) * malloc_size);
	if (new_buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	buffer[line_len] = '\0';
	return (new_buffer);
}

char	*cat_line(ssize_t line_len, char *buffer)
{
	char	*new_buffer;
	ssize_t	i;

	i = 0;
	new_buffer = create_buffer(line_len, buffer);
	if (new_buffer == NULL)
		return (NULL);
	while (buffer[i])
	{
		new_buffer[i] = buffer[i];
		i++;
	}
	new_buffer[i] = '\0';
	free(buffer);
	return (new_buffer);
}
