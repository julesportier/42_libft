/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:00:48 by juportie          #+#    #+#             */
/*   Updated: 2025/02/22 11:55:25 by juportie         ###   ########.fr       */
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

static t_iflag	*set_flag(t_iflag *out, int flag)
{
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
			return (*set_flag(&out, 4));
		if (overflows(out.i, nptr[i] - 48, sign))
			return (*set_flag(&out, 1));
		if (underflows(out.i, nptr[i] - 48, sign))
			return (*set_flag(&out, 2));
		out.i = out.i * 10 + (nptr[i] - 48);
		i++;
	}
	out.i *= sign;
	return (*set_flag(&out, 0));
}
