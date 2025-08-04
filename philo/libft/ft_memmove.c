/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:43:24 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/10/23 14:52:46 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*pdest;
	char		*ldest;
	const char	*lsrc;
	const char	*psrc;

	pdest = dest;
	psrc = src;
	ldest = dest + (n - 1);
	lsrc = src + (n - 1);
	if (pdest == NULL && psrc == NULL)
		return (NULL);
	if (pdest < psrc)
	{
		while (n--)
			*pdest++ = *psrc++;
	}
	else
	{
		while (n--)
			*ldest-- = *lsrc--;
	}
	return (dest);
}
/*
int	main(void)
{
	char	str1[] = "Fast";
	char	str2[] = "Lasting";

//	printf("%s\n", (char *)ft_memmove(str1, str2, 1));
	printf("%s\n", (char *)ft_memmove(str2, str1, 1));
	return (0);
}*/
