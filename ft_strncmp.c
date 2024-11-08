/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:14:17 by juportie          #+#    #+#             */
/*   Updated: 2024/11/08 11:06:19 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (
		s1[i] == s2[i]
		&& !(s1[i] == '\0' && s2[i] == '\0')
		&& i < n
	)
			i++;
	return (s1[i] - s2[i]);
}