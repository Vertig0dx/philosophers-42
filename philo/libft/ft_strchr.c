/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:10:30 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/10/20 12:58:41 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == (char) c)
			return (str);
		str++;
	}
	if (*str == '\0' && (char)c == '\0')
		return (str);
	return (0);
}
/*
int	main(void)
{
	char	str1[10] = "teste";

	printf("%s\n",ft_strchr(0x5566e3d08020: "teste", 357: 'e'));
	printf("%s\n",ft_strchr(str1, 'e'));
	return (0);
}*/
