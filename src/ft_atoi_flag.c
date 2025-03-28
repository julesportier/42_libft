/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:00:48 by juportie          #+#    #+#             */
/*   Updated: 2025/03/28 08:58:27 by juportie         ###   ########.fr       */
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
		out->nbr = out->nbr * -1;
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
	out.nbr = 0;
	out.flag = WRONG_INPUT;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	while (nptr[i])
	{
		out.flag = 0;
		if (!ft_isdigit(nptr[i]))
			return (*set_flag(&out, WRONG_INPUT));
		if (sign == 1 && overflows(out.nbr, nptr[i] - 48))
			return (*set_flag(&out, OVERFLOW));
		if (sign == -1 && underflows(out.nbr, nptr[i] - 48))
			return (*set_flag(&out, UNDERFLOW));
		out.nbr = out.nbr * 10 + (nptr[i] - 48);
		i++;
	}
	out.nbr *= sign;
	return (out);
}
