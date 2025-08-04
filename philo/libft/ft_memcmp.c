/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:48:37 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/10/20 12:58:03 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
		n--;
	}
	return (0);
}
/*
int	main(void)
{
	char	s1[] = "Vettel";
	char	s2[] = "Crash";
	char	s3[] = "Vetrel";

	printf ("%d\n", ft_memcmp(s1, s2, 5));
	printf ("%d\n", ft_memcmp(s1, s3, 5));
	printf ("%d\n", ft_memcmp(s2, s3, 5));
	return (0);
}*/
