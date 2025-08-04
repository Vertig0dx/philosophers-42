/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:51:05 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/10/25 17:32:46 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		i;
	char	*str;

	str = ft_itoa(n);
	i = ft_putstr(str);
	free(str);
	return (i);
}
/*
int	main(void)
{
	printf("%d\n", ft_putnbr(1876));
	return (0);
}*/
