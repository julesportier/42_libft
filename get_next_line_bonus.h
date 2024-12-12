/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:50:05 by juportie          #+#    #+#             */
/*   Updated: 2024/12/12 17:22:11 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

struct s_static_data
{
	char	buffer[FD_MAX][BUFFER_SIZE];
	ssize_t	start[FD_MAX];
	ssize_t	nl_pos[FD_MAX];
	ssize_t	read_ret[FD_MAX];
	ssize_t	ret_len[FD_MAX];
};

char	*ft_cat(char *line, struct s_static_data *data, int fd);
ssize_t	get_line_len(char *buffer, ssize_t max_len);
char	*get_next_line(int fd);

#endif
