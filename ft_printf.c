/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:27:10 by juportie          #+#    #+#             */
/*   Updated: 2024/11/22 15:52:42 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft/libft.h"
#include "printf.h"

int	check_formaters(char c)
{
	char	*formaters;
	int	i;

	formaters = "cspdiuxX%";
	i = 0;
	while (formaters[i])
	{
		if (c == formaters[i])
			return (1);
		i++;
	}
	return (0);
}
	
int	count_formats(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!check_formaters(str[i + 1]))
				return (-1);
			count++;
			if (str[i + 1] == '%')
			{
 				if (++i < 0)
					return (-2);
			}
		}
		if (++i < 0)
			return (-2);
	}
	return (count);
}

int	parse_type(const char format, va_list ap)
{
	int	i;

	i = 0;
	if (format == 'c')
		i = ft_putchar_fd(va_arg(ap, int), 1);
	else if (format == 's')
		i = ft_putstr_fd(va_arg(ap, char *), 1);
	else if (format == 'p')
		ft_putaddress_fd(va_arg(ap, unsigned long), 1, &i);
	else if (format == 'd' || format == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1, &i);
	else if (format == 'u')
		ft_putuibase_fd(va_arg(ap, int), "0123456789", 1, &i);
	else if (format == 'x')
		ft_putuibase_fd(va_arg(ap, int), "0123456789abcdef", 1, &i);
	else if (format == 'X')
		ft_putuibase_fd(va_arg(ap, int), "0123456789ABCDEF", 1, &i);
	else if (format == '%')
		i += ft_putchar_fd('%', 1);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int	f_count;
	int	i;
	int	w_count;

	va_start(ap, str);
	f_count = count_formats(str);
	if (f_count < 0)
		return (-1);
	i = 0;
	w_count = 0;
	while (f_count-- + 1)
	{
		while (str[i] != '%')
		{
			if (str[i] == '\0')
				return (i);
			w_count += write(1, &str[i], 1);
			i++;
		}
		w_count += parse_type(str[++i], ap);
		i++;
	}
	va_end(ap);
	return (w_count);
}

#include <stdio.h>
//int	main(int argc, char **argv)
int	main(void)
{
	//if (argc < 2)
	//{
	//	printf("Give an arg !\n");
	//	return (0);
	//}
	//char *str = "[s format0]";
	//char *str2 = "[s format1]";
	//char	c = 'c';
	//char	*p = str;
	//char	**dp = &p;

	//ft_printf("ft_printf test %s %s char : %c straddress : %p paddress : %p hex 18 == %p\n", str, str2, c, p, dp, (unsigned long)798754);
	//printf("printf straddress %p printf paddress %p\n", p, dp);
	//printf("\n");
	int	i = 0x153;
	unsigned int	ui = 4294967295;
	int	ftcount = 0;
	ftcount = ft_printf("ft_printf d == %d i == %i ui == %u x == %x X == %X\n", i, i, ui, ui, ui);
	printf("ftcount == %d\n", ftcount);
	int	pcount = 0;
	pcount = printf("cl_printf d == %d i == %i ui == %u x == %x X == %X\n", i, i, ui, ui, ui);
	printf("pcount == %d\n", pcount);
	//printf("%s \n", argv[1], argv[2]);
	//printf("%s %s %s %s %s %s %s \n", argv[1]);
	//printf("count -> %d\n", count_args(argv[1]));
	//printf("count -> %d\n", count_args(argv[1]));
	//test_va(4, 1, 2, 3);
	//printf("c -> %05d\n", argv[1][0]);
	//printf("c -> %-7d\n", argv[1][0]);
	//double d = 12345;
	//printf("c -> %#a\n", d);
	//printf("c -> %c\n", argv[1][0]);
	//printf("s -> %s\n", argv[1]);

	// hex pointer
	//printf("p -> %p\n", argv[1]);

	//printf("d -> %d\n", argv[1]);
	//printf("i -> %i\n", argv[1]);
	//printf("u -> %u\n", argv[1]);

	//// hex lowercase
	//printf("x -> %x\n", argv[1]);
	//// hex uppercase
	//printf("X -> %X\n", argv[1]);

	//// print percent sign
	//printf("% -> %%\n", argv[1]);
	return (0);
}
//int	test_va(int n, ...)
//{
//	va_list	ap;
//
//	va_start(ap, n);
//	while (n--)
//		printf("va_arg -> %d\n", va_arg(ap, int));
//	va_end(ap);
//	return (0);
//}
