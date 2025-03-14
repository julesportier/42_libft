/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:27:10 by juportie          #+#    #+#             */
/*   Updated: 2024/11/25 11:12:43 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_formaters(char c)
{
	char	*formaters;
	int		i;

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

static int	count_formats(const char *str)
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

static int	parse_type(const char format, va_list ap)
{
	int	i;

	i = 0;
	if (format == 'c')
		i = ftpf_putchar_fd(va_arg(ap, int), 1);
	else if (format == 's')
		i = ftpf_putstr_fd(va_arg(ap, char *), 1);
	else if (format == 'p')
		ftpf_putaddress_fd(va_arg(ap, unsigned long), 1, &i);
	else if (format == 'd' || format == 'i')
		ftpf_putnbr_fd(va_arg(ap, int), 1, &i);
	else if (format == 'u')
		ftpf_putuibase_fd(va_arg(ap, int), "0123456789", 1, &i);
	else if (format == 'x')
		ftpf_putuibase_fd(va_arg(ap, int), "0123456789abcdef", 1, &i);
	else if (format == 'X')
		ftpf_putuibase_fd(va_arg(ap, int), "0123456789ABCDEF", 1, &i);
	else if (format == '%')
		i += ftpf_putchar_fd('%', 1);
	return (i);
}

static int	close_va_object(va_list ap, int return_value)
{
	va_end(ap);
	return (return_value);
}

// error codes:
// -1 (unrecognised formater), -2 (too many formaters), -3 (no argument)
int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		f_count;
	int		i;
	int		writes_count;

	if (!str)
		return (-3);
	va_start(ap, str);
	f_count = count_formats(str);
	if (f_count < 0)
		return (close_va_object(ap, f_count));
	i = 0;
	writes_count = 0;
	while (f_count-- + 1)
	{
		while (str[i] != '%')
		{
			if (str[i] == '\0')
				return (close_va_object(ap, writes_count));
			writes_count += write(1, &str[i++], 1);
		}
		writes_count += parse_type(str[++i], ap);
		i++;
	}
	return (close_va_object(ap, writes_count));
}
//
//#include <stdio.h>
//#include <limits.h>
////int	main(int argc, char **argv)
//int	main(void)
//{
//	//if (argc < 2)
//	//{
//	//	printf("Give an arg !\n");
//	//	return (0);
//	//}
//	//char *str = "[s format0]";
//	//char *str2 = "[s format1]";
//	//char	c = 'c';
//	//char	*p = str;
//	//char	**dp = &p;
//
//	//int	i = -153;
//	//unsigned int	ui = 4294967295;
//	//unsigned int	ui = -ULONG_MAX;
//	//int	ftcount = 0;
//	//ftcount = ft_printf(
//	//	"ft_printf d == %d i == %i ui == %u x == %x X == %X\n",
//	//	i, i, ui, ui, ui
//	//);
//	//printf("ftcount == %d\n", ftcount);
//	//int	pcount = 0;
//	//pcount = printf(
//	//	"cl_printf d == %d i == %i ui == %u x == %x X == %X\n",
//	//	i, i, ui, ui, ui
//	//);
//	//printf("pcount == %d\n", pcount);
//	int	ftcount = 0;
//	ftcount = ft_printf(
//		"%X", 2167
//	);
//	printf("\nftcount == %d\n", ftcount);
//	int	pcount = 0;
//	pcount = printf(
//		"%X", 2167
//	);
//	printf("\npcount == %d\n", pcount);
//	//int	ftcount = 0;
//	//ftcount = ft_printf("%i ; %s ; %p\n", i, NULL, -15, str, i);
//	//printf("ftcount == %d\n", ftcount);
//	//int	pcount = 0;
//	//pcount = printf("%i ; %s ; %p\n", i, NULL, -15, str, i);
//	//printf("pcount == %d\n", pcount);
//	//printf("%s \n", argv[1], argv[2]);
//	return (0);
//}
