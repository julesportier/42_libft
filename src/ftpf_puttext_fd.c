/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_puttext_fd.c                                    :+:      :+:  :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:45:21 by juportie          #+#    #+#             */
/*   Updated: 2024/11/25 11:12:36 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ftpf_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
		if (i < 0)
			return (-1);
	}
	return (i);
}

int	ftpf_putchar_fd(char c, int fd)
{
	return ((int)write(fd, &c, 1));
}

int	ftpf_putstr_fd(char *s, int fd)
{
	int	s_len;

	if (s == NULL)
		return (ftpf_putstr_fd("(null)", fd));
	s_len = ftpf_strlen(s);
	if (s_len < 0)
		return (-1);
	return ((int)write(fd, s, s_len));
}
