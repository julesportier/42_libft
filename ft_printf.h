/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:31:22 by juportie          #+#    #+#             */
/*   Updated: 2024/11/22 17:17:05 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H 
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_strlen(char *str);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd, int *count);
void	ft_putuibase_fd(unsigned int nbr, char *base, int fd, int *count);
void	ft_putulbase_fd(unsigned long nbr, char *base, int fd, int *count);
void	ft_putaddress_fd(unsigned long address, int fd, int *count);

#endif
