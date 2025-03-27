/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:40:02 by juportie          #+#    #+#             */
/*   Updated: 2025/03/27 11:12:16 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt_floor(int nbr)
{
	int	root;
	int	low;
	int	high;
	int	pivot;

	if (nbr < 0)
		return (-1);
	root = 1;
	low = 1;
	high = nbr;
	while (low <= high)
	{
		pivot = (high - low) / 2 + low;
		if (pivot * pivot <= nbr)
		{
			root = pivot;
			low = pivot + 1;
		}
		else
			high = pivot - 1;
	}
	return (root);
}
