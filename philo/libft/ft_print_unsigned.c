/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:23:59 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/10/25 17:00:55 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_untoa(unsigned int n)
{
	char		*str;
	size_t		len;

	len = ft_numlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	while (n != 0)
	{
		str[len] = n % 10 + 48;
		n = n / 10;
		len--; 
	}
	return (str);
}

int	ft_print_unsigned(unsigned int n)
{
	int		i;
	char	*str;

	i = 0;
	if (n == 0)
		i = i + write (1, "0", 1);
	else
	{
		str = ft_untoa(n);
		i = i + ft_putstr(str);
		free(str);
	}
	return (i);
}
/*
int main(void)
{
	ft_print_unsigned(4294967295);
}
*/
