/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:55:18 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/10/23 14:41:52 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_setnbr(long number, char *str, size_t len)
{
	if (number == 0)
		str[0] = '0';
	if (number < 0)
	{
		str[0] = '-';
		number = number * -1;
	}
	len--;
	while (number != 0)
	{
		str[len] = number % 10 + '0';
		number = number / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	long		number;

	len = 0;
	number = (long) n;
	len = ft_numlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str = ft_setnbr(number, str, len);
	str[len] = '\0';
	return (str);
}
/*
int	main(void)
{
	printf("%s\n", ft_itoa(-1234));
}*/