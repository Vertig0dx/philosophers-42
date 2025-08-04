/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:23:50 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/10/23 12:53:14 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	if (start > end)
		return (ft_strdup(s1 + end + 1));
	while (ft_strchr(set, s1[end]) && s1[end])
		end--;
	str = ft_substr(s1, start, end - start + 1);
	if (str == NULL)
		return (NULL);
	return (str);
}

/*
int main(void)
{
	char str1[] = "&&&&remove these damn & &&&&&";

	printf("%s\n", ft_strtrim(str1, "&"));
	return (0);
}
*/