/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:00:48 by juportie          #+#    #+#             */
/*   Updated: 2024/11/13 09:36:04 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	overflows(long long nbr, int next_nbr, int sign)
{
	if (
		nbr * sign > 0
		&& (nbr * 10 + next_nbr) * sign <= 0
	)
		return (1);
	return (0);
}

static int	underflows(long long nbr, int next_nbr, int sign)
{
	if (
		nbr * sign < 0
		&& (nbr * 10 + next_nbr) * sign >= 0
	)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long long	out;

	i = 0;
	sign = 1;
	out = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		if (overflows(out, nptr[i] - 48, sign))
			return (-1);
		else if (underflows(out, nptr[i] - 48, sign))
			return (0);
		out = out * 10 + (nptr[i] - 48);
		i++;
	}
	return (out * sign);
}
