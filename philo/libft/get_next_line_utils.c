/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:38:55 by lmiguel-          #+#    #+#             */
/*   Updated: 2024/02/01 16:24:25 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	if (!str)
		return (NULL);
	if ((char)c == 0)
		return (str);
	while (*str != '\0')
	{
		if (*str == (char) c)
			return (str);
		str++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char*s2)
{
	int		i;
	int		j;
	size_t	len1;	
	char	*str;

	len1 = (ft_strlen_gnl(s1) + ft_strlen_gnl(s2));
	str = (char *)malloc(sizeof(char) * (len1 + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	if (s1)
		free (s1);
	if (s2)
		free (s2);
	return (str);
}

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}
