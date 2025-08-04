/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:23:37 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/10/20 12:59:06 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = NULL;
	while (*s != '\0')
	{
		if (*s == (char) c)
			str = (char *) s;
		s++;
	}
	if (*s == '\0' && (char)c != '\0')
		return (str);
	if (*s == '\0' && (char)c == '\0')
		return ((char *) s);
	return (0);
}
/*
int	main(void)
{
	char	str1[9] = "";

	printf("%s\n", strrchr(str1, 'i'));
	printf("%s\n", ft_strrchr(str1, 'i'));
	return (0);
}*/
