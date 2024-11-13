/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:52:03 by juportie          #+#    #+#             */
/*   Updated: 2024/11/13 15:10:49 by juportie         ###   ########.fr       */
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
	char	dest[] = "abcdefgxxxx";
	//char	pad[] = "padpadpad";
	char	dest2[] = "abcdefgxxxx";
	//ft_memmove(dest, src, 7);
	//printf("%s\n", dest);
	//memmove(dest2, src2, 7);
	//printf("%s\n", dest2);
	ft_memmove(dest + 4, dest, 3);
	ft_putendl_fd(dest, 1);
	memmove(dest2 + 4, dest2, 3);
	ft_putendl_fd(dest2, 1);
	//ft_memmove(dest, dest + 2, 5);
	//ft_putendl_fd(dest, 1);
	//memmove(dest2, dest2 + 2, 5);
	//ft_putendl_fd(dest2, 1);
	printf("\n");
}

//void	test_ft_strlcpy()
//{
//	char	src[] = "012";
//	char	dst[] = "abcdefg";
//	char	src2[] = "012";
//	char	dst2[] = "abcdefg";
//	int	size = 5;
//
//	size_t	ft_ret = ft_strlcpy(dst, src, size);
//	write(1, dst, 7);
//	write(1, "\n", 1);
//	ft_ret += '0';
//	write(1, &ft_ret, 1);
//	write(1, "\n", 1);
//	size_t	cl_ret = strlcpy(dst2, src2, size);
//	write(1, dst2, 7);
//	write(1, "\n", 1);
//	cl_ret += '0';
//	write(1, &cl_ret, 1);
//	write(1, "\n", 1);
//}

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
	char	*ft = ft_strchr(s, c);
	char	*fc = strchr(s, c);
	printf("ft: %s %p\n", ft, ft);
	printf("fc: %s %p\n", fc, fc);
	//write(1, ft_strchr(s, c), 10);
	//write(1, "\n", 1);
	//write(1, strchr(s, c), 10);
	//write(1, "\n", 1);
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

void	test_ft_strncmp(const char *s1, const char *s2, size_t n)
{
	printf("ft_strncmp: %d\n", ft_strncmp(s1, s2, n));
	printf("strncmp: %d\n", strncmp(s1, s2, n));
}

void	test_ft_memchr()
{
	int	size = 7;
	int	chr = '\200';
	char	*str = "test\200";
	printf("ft_memchr: %p\n", (char *)ft_memchr(str, chr, size));
	printf("memchr: %p\n", (char *)memchr(str, chr, size));
}

void	test_ft_memcmp(const void *s1, const void *s2, size_t n)
{
	printf("ft_memcmp: %d\n", ft_memcmp(s1, s2, n));
	printf("memcmp: %d\n", memcmp(s1, s2, n));
}

//void	test_ft_strnstr (const char *big, const char *little, size_t len)
//{
//	printf("ft_strnstr: %s\n", ft_strnstr(big, little, len));
//	printf("strnstr: %s\n", strnstr(big, little, len));
//}

void	test_ft_atoi(const char *nptr)
{
	int	atoi_str;
	int	ft_atoi_str;

	atoi_str = printf("atoi: %d\n", atoi(nptr));
	ft_atoi_str = printf("ft_atoi: %d\n", ft_atoi(nptr));
}

void	test_ft_calloc(size_t nmemb, size_t size)
{
	//printf("calloc ret: %s\n", (char *)calloc(nmemb, size));
	ft_putstr_fd("calloc: ", 1);
	ft_putchar_fd(*(char *)calloc(nmemb, size), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("ft_calloc: ", 1);
	// the true calloc return NULL if nmemb * size < 0, not mine
	ft_putchar_fd(*(char *)ft_calloc(nmemb, size), 1);
	ft_putchar_fd('\n', 1);
}

void	test_ft_strdup(const char *s)
{
	char	*dup;
	char	*ft_dup;

	printf("s address: %p\n", s);
	dup = strdup(s);
	printf("strdup: %s\nstrdup adress: %p\n", dup, dup);
	ft_dup = ft_strdup(s);
	printf("dup: %s\ndup adress: %p\n", ft_dup, ft_dup);
}

void	test_ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;

	printf("s address: %p\n", s);
	sub = ft_substr(s, start, len);
	printf("ft_substr: %s\nft_substr adress: %p\n", sub, sub);
}

void	test_ft_strjoin(const char *s1, const char *s2)
{
	char	*joined;

	printf("s1 address: %p\n", s1);
	joined = ft_strjoin(s1, s2);
	printf("ft_strjoin: %s\nft_strjoin adress: %p\n", joined, joined);
}

void	test_ft_strtrim(char const *s1, char const *set)
{
	char	*trimed;

	printf("s1 address: %p\n", s1);
	trimed = ft_strtrim(s1, set);
	printf("ft_strtrim: %s\nft_strtrim adress: %p\n", trimed, trimed);
}

void	test_ft_split(char const *s, char c, size_t splits_nbr)
{
	char	**splits;
	size_t	i;

	i = 0;
	splits = ft_split(s, c);
	while (i < splits_nbr)
	{
		printf("split[%zu]: %s\n", i, splits[i]);
		i++;
	}
	free(splits);
	splits = NULL;
}

void	test_ft_itoa(int n)
{
	char	*str;

	str = ft_itoa(n);
	printf("itoa %d -> %s\n", n, str);
}

void	test_ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	printf("strmapi(%s, f) -> %s\n", s, ft_strmapi(s, f));
}
char	p_func_map(unsigned int i, char c)
{
	c = c + i;
	return (c);
}

void	test_ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	printf("s -> %s\n", s);
	ft_striteri(s, f);
	printf("strteri() -> %s\n", s);
}
void	p_func_iter(unsigned int i, char *c)
{
	*c = *c + i;
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
		//test_ft_strchr("teste", 'e' + 256);
		//test_ft_strrchr(argv[1], argv[2][0]);
		//test_ft_strrchr(argv[1], '\0');
		//test_ft_strncmp(argv[1], argv[2], 8);
		//test_ft_strncmp("\200", "\0", 8);
		//test_ft_strncmp("\0", "\200", 8);
		//test_ft_strncmp("123", "124", 8);
		//test_ft_strncmp("abcdefgh", "abcdxyz", 5);
		test_ft_memchr();
		//test_ft_memcmp(argv[1], argv[2], -10);
		//test_ft_strnstr(argv[1], argv[2], 15);
		//test_ft_atoi("      \n\t\v\f\r -9223372036854775806");
		//test_ft_atoi("  -2147483649");
		//test_ft_calloc(2147483640, 1);
		//test_ft_calloc(5000000000, 1);
		//test_ft_strdup(argv[1]);
		//test_ft_substr(argv[1], 3, 6);
		//test_ft_strjoin(argv[1], argv[2]);
		//test_ft_strtrim(argv[1], argv[2]);
		//test_ft_split(argv[1], argv[2][0], 7);
		//test_ft_itoa(atoi(argv[1]));
		//test_ft_itoa(-2540090);
		//test_ft_strmapi(argv[1], p_func_map);
		//test_ft_striteri(argv[1], p_func_iter);
		//ft_putchar_fd('a', 1);
		//ft_putstr_fd("put str\n", 1);
		//ft_putendl_fd("putendl", 1);
		//ft_putnbr_fd(ft_atoi(argv[1]), 1);
		return (0);
	}
	else
	{
		printf("argv[0] == %s\n", argv[0]);
		return (1);
	}
}
