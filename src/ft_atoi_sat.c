/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_sat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:16:29 by juportie          #+#    #+#             */
/*   Updated: 2025/02/25 09:39:26 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	overflows(int nbr, int next_nbr, int sign)
{
	if (
		nbr * sign > 0
		&& (nbr * 10 + next_nbr) * sign <= 0
	)
		return (1);
	return (0);
}

static int	underflows(int nbr, int next_nbr, int sign)
{
	if (
		nbr * sign < 0
		&& (nbr * 10 + next_nbr) * sign >= 0
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
		if (overflows(out, nptr[i] - 48, sign))
			return (INT_MAX);
		else if (underflows(out, nptr[i] - 48, sign))
			return (INT_MIN);
		out = out * 10 + (nptr[i] - 48);
		i++;
	}
	return (out * sign);
}
