/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumbers_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:27:05 by juportie          #+#    #+#             */
/*   Updated: 2024/11/22 15:48:05 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr_fd(int n, int fd, int *count)
{
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd, count);
		*count += ft_putchar_fd((n % 10) + 48, fd);
	}
	else if (n < 0)
	{
		if (n == -2147483648)
		{
			*count += ft_putstr_fd("-2147483648", fd);
			return ;
		}
		*count += ft_putchar_fd('-', fd);
		n *= -1;
		ft_putnbr_fd(n, fd, count);
	}
	else
		*count += ft_putchar_fd(n + 48, fd);
}

void	ft_putulbase_fd(unsigned long nbr, char *base, int fd, int *count)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (base_len < 1)
		return ;
	if (nbr > 9)
	{
		ft_putulbase_fd(nbr / base_len, base, fd, count);
		*count += ft_putchar_fd(base[(nbr % base_len)], fd);
	}
	else if (nbr != 0)
		*count += ft_putchar_fd(base[nbr], fd);
}

void	ft_putuibase_fd(unsigned int nbr, char *base, int fd, int *count)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (base_len < 1)
		return ;
	if (nbr > 9)
	{
		ft_putulbase_fd(nbr / base_len, base, fd, count);
		*count += ft_putchar_fd(base[(nbr % base_len)], fd);
	}
	else if (nbr != 0)
		*count += ft_putchar_fd(base[nbr], fd);
}

void	ft_putaddress_fd(unsigned long address, int fd, int *count)
{
	*count += ft_putstr_fd("0x", fd);
	ft_putulbase_fd(address, "0123456789abcdef", fd, count);
}
