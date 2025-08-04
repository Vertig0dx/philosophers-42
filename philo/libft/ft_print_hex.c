/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:23:32 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/11/09 12:45:17 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static void	ft_morph_hex(unsigned int n, const char type)
{
	const char	*baselow;
	const char	*baseup;

	baselow = "0123456789abcdef";
	baseup = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_morph_hex(n / 16, type);
		ft_morph_hex(n % 16, type);
	}
	else
	{
		if (type == 'x')
			ft_putchar(baselow[n]);
		if (type == 'X')
			ft_putchar(baseup[n]);
	}
}

int	ft_print_hex(unsigned int n, const char type)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_morph_hex(n, type);
	return (ft_hexlen(n));
}

/*
int main(void)
{
	printf("%d\n", ft_print_hex(15, 'x'));
}
*/