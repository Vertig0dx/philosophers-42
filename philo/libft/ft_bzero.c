/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:27:49 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/10/20 12:57:32 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n > 0)
	{
		*ptr = '\0';
		n--;
		ptr++;
	}
}
/*
int	main(void)
{
	char	str[11] = "Erase this";

	ft_bzero(str, 5);
//	bzero(str, 5);
	printf("%s\n", str);
	return (0);
}*/
