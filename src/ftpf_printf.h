/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:31:22 by juportie          #+#    #+#             */
/*   Updated: 2024/11/25 11:12:16 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPF_PRINTF_H 
# define FTPF_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ftpf_strlen(char *str);
int		ftpf_putchar_fd(char c, int fd);
int		ftpf_putstr_fd(char *s, int fd);
void	ftpf_putnbr_fd(int n, int fd, int *count);
void	ftpf_putuibase_fd(unsigned int nbr, char *base, int fd, int *count);
void	ftpf_putulbase_fd(unsigned long nbr, char *base, int fd, int *count);
void	ftpf_putaddress_fd(unsigned long address, int fd, int *count);

#endif
