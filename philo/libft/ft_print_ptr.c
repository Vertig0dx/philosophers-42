/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:02:50 by lmiguel-          #+#    #+#             */
/*   Updated: 2024/02/02 15:40:37 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_countptr(unsigned long long ptr)
{
	int	i;

	i = 0;
	while (ptr != 0)
	{
		ptr = ptr / 16;
		i++;
	}
	return (i);
}

static int	ft_morph_ptr(unsigned long long ptr)
{
	const char	*base;

	base = "0123456789abcdef";
	if (ptr >= 16)
	{
		ft_morph_ptr(ptr / 16);
		ft_morph_ptr(ptr % 16);
	}
	else
		ft_putchar(base[ptr]);
	return (ft_countptr(ptr));
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	i;

	i = 0;
	if (ptr == 0)
	{
		i = i + (write(1, "(nil)", 5));
		return (i);
	}
	i = write (1, "0x", 2);
	i = i + (ft_morph_ptr(ptr));
	return (i);
}
/*
int	main(void)
{
	
	printf("%d\n", ft_print_ptr(1844674407370955161));
	return (0);
}
*/