/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:00:16 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/10/20 12:58:27 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n > 0)
	{
		*ptr = c;
		n--;
		ptr++;
	}
	return (s);
}
/*
int	main(void)
{
	char str[30] = "Switch this with that.";
	ft_memset(str, 'O', 30);
	//memset(str, 'O', 30);
	printf("%s\n", str);
	return (0);
}*/
