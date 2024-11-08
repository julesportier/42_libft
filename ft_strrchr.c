/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:10:21 by juportie          #+#    #+#             */
/*   Updated: 2024/11/08 09:15:07 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	slen;
	char	*last;

	i = 0;
	slen = ft_strlen(s) + 1;
	last = NULL;
	while (i < slen)
	{
		if (s[i] == c)
			last = (char *)&s[i];
		i++;
	}
	return (last);
}
