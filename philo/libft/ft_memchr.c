/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:53:52 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/10/20 12:58:00 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;

	ptr = (const unsigned char *) s;
	while (n != 0)
	{
		if (*ptr == (unsigned char) c)
			return ((unsigned char *)ptr);
		n--;
		ptr++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str[] = "Ground";
	printf("%s\n", (char *)ft_memchr(str, 'o', 5));
	return (0);
}*/
