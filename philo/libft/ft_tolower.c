/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:07:31 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/10/20 12:59:31 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}
/*
int	main(void)
{
	int a = 'g';
	int b = 'G';
	int c = '0';
	int d = '~';

	printf("%d\n", ft_tolower(a));
	printf("%d\n", ft_tolower(b));
	printf("%d\n", ft_tolower(c));
	printf("%d\n", ft_tolower(d));
	return (0);
}*/
