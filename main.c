/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:52:03 by juportie          #+#    #+#             */
/*   Updated: 2024/11/08 09:48:02 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <bsd/string.h>

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
	//char	src[] = "0123456";
	//char	src2[] = "0123456";
	char	dest[] = "abcdefg";
	//char	pad[] = "padpadpad";
	char	dest2[] = "abcdefg";
	//ft_memcpy(dest, src, 7);
	//printf("%s\n", dest);
	//memcpy(dest2, src2, 7);
	//printf("%s\n", dest2);
	ft_memcpy(dest + 2, dest, 5);
	ft_putendl_fd(dest, 1);
	//ft_putendl_fd(pad, 1);
	memcpy(dest2 + 2, dest2, 5);
	ft_putendl_fd(dest2, 1);
	printf("\n");
}

void	test_ft_memmove()
{
	//char	src[] = "0123456";
	//char	src2[] = "0123456";
	char	dest[] = "abcdefg";
	//char	pad[] = "padpadpad";
	char	dest2[] = "abcdefg";
	//ft_memmove(dest, src, 7);
	//printf("%s\n", dest);
	//memmove(dest2, src2, 7);
	//printf("%s\n", dest2);
	ft_memmove(dest + 4, dest, 3);
	ft_putendl_fd(dest, 1);
	//ft_putendl_fd(pad, 1);
	memmove(dest2 + 4, dest2, 3);
	ft_putendl_fd(dest2, 1);
	printf("\n");
}

void	test_ft_strlcpy()
{
	char	src[] = "012";
	char	dst[] = "abcdefg";
	char	src2[] = "012";
	char	dst2[] = "abcdefg";
	int	size = 5;

	size_t	ft_ret = ft_strlcpy(dst, src, size);
	write(1, dst, 7);
	write(1, "\n", 1);
	ft_ret += '0';
	write(1, &ft_ret, 1);
	write(1, "\n", 1);
	size_t	cl_ret = strlcpy(dst2, src2, size);
	write(1, dst2, 7);
	write(1, "\n", 1);
	cl_ret += '0';
	write(1, &cl_ret, 1);
	write(1, "\n", 1);
}

void	test_ft_strlcat()
{
	char	src[3] = {30,31,32};
	//char	dst[] = "test ";
	char	dst[4] = {'t','e','s','t'};
	//char	src2[3] = {30,31,32};
	//char	dst2[4] = {'t','e','s','t'};
	int	size = 3;

	size_t	ft_ret = ft_strlcat(dst, src, size);
	write(1, dst, 10);
	write(1, "\n", 1);
	ft_ret += '0';
	write(1, &ft_ret, 1);
	write(1, "\n", 1);
	//size_t	cl_ret = strlcat(dst, src, size);
	//write(1, dst, 10);
	//write(1, "\n", 1);
	//cl_ret += '0';
	//write(1, &cl_ret, 1);
	//write(1, "\n", 1);
}

void	test_ft_toupper(int c)
{
	printf("%c\n", ft_toupper(c));
	printf("%c\n", toupper(c));
}

void	test_ft_tolower(int c)
{
	printf("%c\n", ft_tolower(c));
	printf("%c\n", tolower(c));
}

void	test_ft_strchr(const char *s, int c)
{
	printf("%s\n", ft_strchr(s, c));
	printf("%s\n", strchr(s, c));
	write(1, ft_strchr(s, c), 10);
	write(1, "\n", 1);
	write(1, strchr(s, c), 10);
	write(1, "\n", 1);
}

void	test_ft_strrchr(const char *s, int c)
{
	//printf("%s\n", ft_strrchr(s, c));
	//printf("%s\n", strrchr(s, c));
	write(1, ft_strrchr(s, c), 10);
	write(1, "\n", 1);
	write(1, strrchr(s, c), 10);
	write(1, "\n", 1);
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
		//test_ft_memmove();
		//test_ft_strlcpy();
		//test_ft_strlcat();
		//test_ft_toupper(argv[1][0]);
		//test_ft_tolower(argv[1][0]);
		//test_ft_strchr(argv[1], argv[2][0]);
		//test_ft_strchr(argv[1], '\0');
		test_ft_strrchr(argv[1], argv[2][0]);
		test_ft_strrchr(argv[1], '\0');
		//ft_putchar_fd('a', 1);
		//ft_putstr_fd("put str\n", 1);
		//ft_putendl_fd("putendl", 1);
		return (0);
	}
	else
	{
		printf("argv[0] == %s\n", argv[0]);
		return (1);
	}
}
