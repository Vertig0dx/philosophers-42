/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:51:50 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/10/20 12:59:44 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
/*
int	main(void)
{	
	int	a = 'g';
	int	b = 'G';
	int	c = '0';
	int	d = ' ';

	printf("%d\n", ft_toupper(a));
	printf("%d\n", ft_toupper(b));
	printf("%d\n", ft_toupper(c));
	printf("%d\n", ft_toupper(d));
	return (0);
}*/
