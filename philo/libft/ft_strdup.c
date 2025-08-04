/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:07:44 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/10/23 12:47:03 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*copy;

	size = ft_strlen(s) + 1;
	copy = (char *)malloc(size);
	if (copy == NULL)
		return (NULL);
	(void)ft_memcpy(copy, s, size);
	return (copy);
}

/*
int main(void)
{
	char str1[] = "up we go";
	
	printf("%s\n", ft_strdup(str1));
	return (0);
}
*/