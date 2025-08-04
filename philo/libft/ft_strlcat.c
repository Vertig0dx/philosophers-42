/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:56:55 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/10/20 12:58:50 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
int	ft_strlen(const char *s1)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	return (i);
}
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*s;
	char		*d;
	size_t		n;
	size_t		dstlen;

	d = dst;
	s = src;
	n = size;
	while (n-- != '\0' && *d != '\0')
		d++;
	dstlen = d - dst;
	n = size - dstlen;
	if (n == '\0')
		return (dstlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dstlen + (s - src));
}
/*
int	main(void)
{
	char	str1[20] = "Go big";
	char	str2[20] = "or go home";

	printf("%ld\n", ft_strlcat(str1, str2, 20));
	return (0);
}*/
