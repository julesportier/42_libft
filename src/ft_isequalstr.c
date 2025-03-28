/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isequalstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 08:31:34 by juportie          #+#    #+#             */
/*   Updated: 2025/03/28 08:39:55 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isequalstr(char *str_a, char *str_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_strlen(str_a);
	len_b = ft_strlen(str_b);
	if (len_a == len_b && ft_strncmp(str_a, str_b, len_a) == 0)
		return (1);
	else
		return (0);
}
