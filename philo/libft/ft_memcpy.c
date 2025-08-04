/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:27:51 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/10/23 14:46:40 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*pdest;
	const char	*psrc;

	pdest = dest;
	psrc = src;
	if (pdest == NULL && psrc == NULL)
		return (NULL);
	while (n > 0)
	{
		*pdest = *psrc;
		n--;
		pdest++;
		psrc++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	s1[] = "Ryu";
	char	s2[] = "Koi";

	printf("%s\n", (char *)ft_memcpy(s1, s2, 1));
	return (0);
}*/
