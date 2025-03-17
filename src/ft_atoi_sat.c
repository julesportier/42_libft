/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_sat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:16:29 by juportie          #+#    #+#             */
/*   Updated: 2025/03/14 12:02:50 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	overflows(int nbr, int next_nbr)
{
	if (
		(nbr != 0 || next_nbr != 0)
		&& (ft_ismuloverflow(nbr, 10)
		|| nbr * 10 + next_nbr <= 0)
	)
		return (1);
	return (0);
}

static int	underflows(int nbr, int next_nbr)
{
	if (
		(nbr != 0 || next_nbr != 0)
		&& (ft_ismuloverflow(nbr, 10)
		|| nbr * -10 - next_nbr >= 0)
	)
		return (1);
	return (0);
}

int	ft_atoi_sat(const char *nptr)
{
	int	i;
	int	sign;
	int	out;

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
		if (sign == 1 && overflows(out, nptr[i] - 48))
			return (INT_MAX);
		else if (sign == -1 && underflows(out, nptr[i] - 48))
			return (INT_MIN);
		out = out * 10 + (nptr[i] - 48);
		i++;
	}
	return (out * sign);
}
