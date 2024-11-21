/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:27:10 by juportie          #+#    #+#             */
/*   Updated: 2024/11/21 11:29:25 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"

#include <stdio.h>

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

//int	parse_type(const char format)

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int	f_count;
	int	i;

	va_start(ap, str);
	f_count = count_formats(str);
	if (f_count < 0)
		return (-1);
	//printf("count == %d\n", f_count);
	i = 0;
	while (f_count-- + 1)
	{
		while (str[i] != '%')
		{
			if (str[i] == '\0')
				return (i);
			write(1, &str[i], 1);
			i++;
		}
		//ft_putstr_fd("check\n", 1);
		i++;
		//write(1, va_arg(ap, char *), 1);
		//return (-99);
		ft_putstr_fd(va_arg(ap, char *), 1);
		i++;

		//put_format(&str[i]);
	}

	//va_arg(ap, char *);
	va_end(ap);
	return (0);
}

//int	main(int argc, char **argv)
int	main(void)
{
	//if (argc < 2)
	//{
	//	printf("Give an arg !\n");
	//	return (0);
	//}
	char *str = "[s format]";
	ft_printf("test %s %s kjashdd\n", str, str);
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
