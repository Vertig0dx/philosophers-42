/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:11:55 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/10/23 12:42:38 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	size;
	unsigned int	i;

	size = ft_strlen(s);
	i = 0;
	str = (char *)malloc (sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
char test(unsigned int i, char str)
{
	i = 32;
	if (str >= 'a' && str <= 'z')
		str = str - i;
	return (str);
}

int main(void)
{
	char str1[] = "up we go";
	
	printf("%s\n", ft_strmapi(str1, test));
	return 0;
}
*/