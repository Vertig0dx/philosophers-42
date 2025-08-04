/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:37:18 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/10/20 12:59:03 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (i < len && little[j] != '\0' && big[i] != '\0'
			&& little [j] == big[i])
		{
			++i;
			++j;
		}
		if (little[j] == '\0')
			return ((char *)&big[i - j]);
		i = i - j + 1;
	}
	return (0);
}
/*
int	main(void)
{
	char	str1[20] = "Can't win 'em all";
	char	str2[4] = "win";

	printf("%s\n", ft_strnstr(str1, str2, 15));
	return (0);
}*/
