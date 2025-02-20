/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:25:55 by juportie          #+#    #+#             */
/*   Updated: 2025/02/20 15:22:52 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	get_hex_pos(char digit)
{
	char	*lbase;
	char	*ubase;
	int		i;

	lbase = "0123456789abcdef";
	ubase = "0123456789ABCDEF";
	i = 0;
	while (i < 16)
	{
		if (lbase[i] == digit)
			return (i);
		if (ubase[i] == digit)
			return (i);
		i++;
	}
	return (-1);
}

unsigned int	ft_uhextoui(const char *nptr)
{
	int				i;
	unsigned int	nbr;
	int				pos;
	unsigned int	tmp;

	i = 0;
	nbr = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == ' ')
		i++;
	if (ft_strnstr(nptr + i, "0x", 2))
		i += 2;
	while (nptr[i])
	{
		pos = get_hex_pos(nptr[i]);
		if (pos == -1)
			return (nbr);
		tmp = nbr * 16 + pos;
		if (tmp < nbr)
			return (UINT_MAX);
		nbr = tmp;
		i++;
	}
	return (nbr);
}
