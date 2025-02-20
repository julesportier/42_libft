/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:32:10 by juportie          #+#    #+#             */
/*   Updated: 2025/02/20 10:55:43 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	get_base_pos(char digit, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == digit)
			return (i);
		i++;
	}
	return (-1);
}

unsigned int	ft_atoui_base(const char *nptr, char *base)
{
	int				i;
	unsigned int	nbr;
	int				base_len;
	int				pos;
	unsigned int	tmp;

	i = 0;
	nbr = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == ' ')
		i++;
	base_len = ft_strlen(base);
	while (nptr[i])
	{
		pos = get_base_pos(nptr[i], base);
		if (pos == -1)
			return (nbr);
		tmp = nbr * base_len + pos;
		if (tmp < nbr)
			return (UINT_MAX);
		nbr = tmp;
		i++;
	}
	return (nbr);
}
