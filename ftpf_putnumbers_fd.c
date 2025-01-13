/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_putnumbers_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:27:05 by juportie          #+#    #+#             */
/*   Updated: 2024/11/25 11:12:28 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_printf.h"

void	ftpf_putnbr_fd(int n, int fd, int *count)
{
	if (n > 9)
	{
		ftpf_putnbr_fd(n / 10, fd, count);
		*count += ftpf_putchar_fd((n % 10) + 48, fd);
	}
	else if (n < 0)
	{
		if (n == -2147483648)
		{
			*count += ftpf_putstr_fd("-2147483648", fd);
			return ;
		}
		*count += ftpf_putchar_fd('-', fd);
		n *= -1;
		ftpf_putnbr_fd(n, fd, count);
	}
	else
		*count += ftpf_putchar_fd(n + 48, fd);
}

void	ftpf_putulbase_fd(unsigned long nbr, char *base, int fd, int *count)
{
	unsigned long	base_len;

	base_len = ftpf_strlen(base);
	if (base_len < 1)
		return ;
	if (nbr > base_len - 1)
	{
		ftpf_putulbase_fd(nbr / base_len, base, fd, count);
		*count += ftpf_putchar_fd(base[(nbr % base_len)], fd);
	}
	else
		*count += ftpf_putchar_fd(base[nbr], fd);
}

void	ftpf_putuibase_fd(unsigned int nbr, char *base, int fd, int *count)
{
	unsigned int	base_len;

	base_len = ftpf_strlen(base);
	if (base_len < 1)
		return ;
	if (nbr > base_len - 1)
	{
		ftpf_putulbase_fd(nbr / base_len, base, fd, count);
		*count += ftpf_putchar_fd(base[(nbr % base_len)], fd);
	}
	else
		*count += ftpf_putchar_fd(base[nbr], fd);
}

void	ftpf_putaddress_fd(unsigned long address, int fd, int *count)
{
	if (address)
	{
		*count += ftpf_putstr_fd("0x", fd);
		ftpf_putulbase_fd(address, "0123456789abcdef", fd, count);
	}
	else
		*count += ftpf_putstr_fd("(nil)", fd);
}
