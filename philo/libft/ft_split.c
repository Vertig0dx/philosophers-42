/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:12:59 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/10/23 15:20:21 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_detectcount(const char *str, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static int	ft_stralloc(char **arr, const char *str, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	n;

	i = 0;
	j = 0;
	n = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		j = i;
		while (str[j] != '\0' && str[j] != c)
			j++;
		if (str[j] == c || j > i)
		{
			arr[n] = ft_substr(str, i, j - i);
			if (arr[n] == NULL)
				return (0);
			n++;
			i = j;
		}
	}
	arr[n] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	count;
	unsigned int	i;
	char			**result;

	count = ft_detectcount(s, c);
	i = 0;
	result = (char **)malloc (sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	if (ft_stralloc (result, s, c) == 0)
	{
		while (i < count)
		{
			free (result[i]);
			i++;
		}
		free (result);
		return (NULL);
	}
	return (result);
}
/*
int main(void)
{
	char **array;
	char str1[] = "2334";
	int n;
	
	n = 0;
	array = ft_split(str1, '1');
	while(array[n])
	{
		printf("%s\n", array[n]);
		n++;
	}
	printf("%s", array[n]);
	return (0);
}
*/