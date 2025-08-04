/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:47:37 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/10/20 12:57:53 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	int	a = '\n';
	int	b = 'o';
	int	c = ' ';

	printf ("%d\n", ft_isprint(a));
	printf ("%d\n", ft_isprint(b));
	printf ("%d\n", ft_isprint(c));
	return (0);
}*/
