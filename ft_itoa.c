/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 08:47:42 by juportie          #+#    #+#             */
/*   Updated: 2024/11/12 11:37:25 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_neg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

int	get_pow(int n)
{
	int	i;

	i = 0;
	while (n / 10 > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str_nbr;
	int		p;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = is_neg(n);
	if (sign)
		n *= -1;
	p = get_pow(n);
	str_nbr = malloc((p + sign + 2) * sizeof(char));
	if (str_nbr == NULL)
		return (NULL);
	str_nbr[p + 1 + sign] = '\0';
	if (sign)
		str_nbr[0] = '-';
	while (p > 0)
	{
		str_nbr[p + sign] = n % 10 + 48;
		n /= 10;
		p--;
	}
	str_nbr[sign] = n + 48;
	return (str_nbr);
}
