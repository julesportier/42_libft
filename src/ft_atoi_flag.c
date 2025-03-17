/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:00:48 by juportie          #+#    #+#             */
/*   Updated: 2025/03/14 12:06:19 by juportie         ###   ########.fr       */
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

static t_iflag	*set_flag(t_iflag *out, int flag)
{
	if (flag == UNDERFLOW)
		out->i = out->i * -1;
	out->flag = flag;
	return (out);
}

t_iflag	ft_atoi_flag(const char *nptr)
{
	int		i;
	int		sign;
	t_iflag	out;

	i = 0;
	sign = 1;
	out.i = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
			return (*set_flag(&out, WRONG_INPUT));
		if (sign == 1 && overflows(out.i, nptr[i] - 48))
			return (*set_flag(&out, OVERFLOW));
		if (sign == -1 && underflows(out.i, nptr[i] - 48))
			return (*set_flag(&out, UNDERFLOW));
		out.i = out.i * 10 + (nptr[i] - 48);
		i++;
	}
	out.i *= sign;
	return (*set_flag(&out, 0));
}
