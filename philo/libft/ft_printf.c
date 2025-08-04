/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:45:14 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/11/07 13:14:31 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
neccessary conversions: c = Ascii; s = string; 
p = void * pointer argument as hexadecimal;
d,i = decimal; u = unsigned decimal; x = hexadecimal using abcdef; 
X = hexadecimal using ABCDEF;
% = prints %, conversion specification MUST be %%
*/

static int	ft_detect_arg(va_list args, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg (args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_print_ptr((va_arg(args, unsigned long long))));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar('%') + ft_putchar(format));
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	size_t	i;
	int		len;

	if (!input)
		return (-1);
	i = 0;
	len = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%')
		{
			len = len + ft_detect_arg(args, input[i + 1]);
			i++;
		}
		else
			len = len + ft_putchar(input[i]);
		i++;
	}
	va_end(args);
	return (len);
}
/* 
int	main(void)
{
	printf("This is a string: %s\n", "Hello my friends");
	printf("This is a decimal: %d\n", 451);
	printf("This is a decimal: %i\n", 451);
	printf("This is a pointer: %p\n", (void *)19278959);
	printf("This is a null pointer: %p\n", (void *)0);
	printf("This is an unsigned int: %u\n", 4294967295);
	printf("This is a lowercase hex: %x %X\n", 4294967294);
	printf("This is an uppercase hex: %X\n", 4294967295);
	printf("This is a percentage sign: %s");

	ft_printf("\nThis is a string: %s\n", "Hello my friends");
	ft_printf("This is a decimal: %d\n", 451);
	ft_printf("This is a decimal: %i\n", 451);
	ft_printf("This is a pointer: %p\n", (void *)4294967295);
	ft_printf("This is a null pointer: %p\n", (void *)0);
	ft_printf("This is an unsigned int: %u\n", 4294967295);
	ft_printf("This is a lowercase hex: %x\n", 4294967294);
	ft_printf("This is an uppercase hex: %X\n", 4294967295);
	ft_printf("This is a percentage sign: %s, \n");
	return (0);
}
*/