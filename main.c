/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:52:03 by juportie          #+#    #+#             */
/*   Updated: 2024/11/04 16:18:49 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	ft_isalnum(int c);

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		printf("%d\n", ft_isalnum(argv[1][0]));
		return (0);
	}
	else
		return (1);
}
