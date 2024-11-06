/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:52:03 by juportie          #+#    #+#             */
/*   Updated: 2024/11/06 16:12:19 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

void	test_ft_isalpha(int c)
{
	printf("ft_isalpha(argv[1][0]) -> %d\n", ft_isalpha(c));
	printf("isalpha(argv[1][0]) -> %d\n", isalpha(c));
	printf("ft_isalpha(557) -> %d\n", ft_isalpha(557));
	printf("isalpha(557) -> %d\n", isalpha(557));
	printf("\n");
}

void	test_ft_isascii(int c)
{
	printf("ft_isascii(argv[1][0]) -> %d\n", ft_isascii(c));
	printf("isascii(argv[1][0]) -> %d\n", isascii(c));
	printf("ft_isascii(527) -> %d\n", ft_isascii(527));
	printf("isascii(527) -> %d\n", isascii(527));
	printf("ft_isascii(258) -> %d\n", ft_isascii(258));
	printf("isascii(258) -> %d\n", isascii(258));
	printf("ft_isascii(129) -> %d\n", ft_isascii(129));
	printf("isascii(129) -> %d\n", isascii(129));
	printf("ft_isascii(-1) -> %d\n", ft_isascii(-1));
	printf("isascii(-1) -> %d\n", isascii(-1));
	printf("\n");
}

void	test_ft_isprint(int c)
{
	printf("ft_isprint(argv[1][0]) -> %d\n", ft_isprint(c));
	printf("isprint(argv[1][0]) -> %d\n", isprint(c));
	printf("ft_isprint(127) -> %d\n", ft_isprint(127));
	printf("\n");
}

void	test_ft_strlen(const char *s)
{
	printf("ft_strlen(argv[1]) -> %zu\n", ft_strlen(s));
	printf("strlen(argv[1]) -> %zu\n", strlen(s));
	printf("ft_strlen(\"hello\") -> %zu\n", ft_strlen("hello"));
	printf("strlen(\"hello\") -> %zu\n", strlen("hello"));
	printf("\n");
}

void	test_ft_memset(void *s, int c, size_t n)
{
	char	*mem;
	char	*cmem;
	char	*cs;

	cs = strdup(s);
	mem = ft_memset(s, c, n);
	printf("%s\n", (char *)mem);
	cmem = memset(cs, c, n);
	printf("%s\n", (char *)cmem);
	printf("\n");
}

void	test_ft_bzero(void *s, size_t n)
{
	char	*cs;

	cs = strdup(s);
	ft_bzero(s, n);
	write(1, (char *)s, 5);
	write(1, "\n", 1);
	char	test[] = "estest\0";
	write(1, test, 5);
	write(1, "\n", 1);
	bzero(cs, n);
	write(1, (char *)cs, 5);
	write(1, "\n", 1);
}

void	test_ft_memcpy()
{
	char	src[] = "0123456";
	char	src2[] = "0123456";
	char	dest[] = "abcdefg";
	char	dest2[] = "abcdefg";
	ft_memcpy(dest, src, 7);
	printf("%s\n", dest);
	memcpy(dest2, src2, 7);
	printf("%s\n", dest2);
	//ft_memcpy(dest + 2, dest, 7);
	//printf("%s\n", dest);
	//memcpy(dest2 + 2, dest2, 7);
	//printf("%s\n", dest2);
	printf("\n");
}

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		//test_ft_isalpha(argv[1][0]);
		//test_ft_isascii(argv[1][0]);
		//test_ft_isprint(argv[1][0]);
		//test_ft_strlen(argv[1]);
		//test_ft_memset(argv[1], 'a', 2);
		//test_ft_bzero(argv[1], 2);
		//test_ft_memcpy();
		ft_putchar_fd('a', 1);
		return (0);
	}
	else
	{
		printf("argv[0] == %s\n", argv[0]);
		return (1);
	}
}
