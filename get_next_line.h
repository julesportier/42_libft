/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:23:33 by juportie          #+#    #+#             */
/*   Updated: 2024/12/12 13:53:27 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

struct s_static_data
{
	char	buffer[BUFFER_SIZE];
	ssize_t	start;
	ssize_t	nl_pos;
	ssize_t	read_ret;
	ssize_t	ret_len;
};

char	*ft_cat(char *line, struct s_static_data *data);
ssize_t	get_line_len(char *buffer, ssize_t max_len);
char	*get_next_line(int fd);

#endif
