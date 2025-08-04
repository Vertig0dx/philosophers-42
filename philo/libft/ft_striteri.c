/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:15:57 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/10/20 15:51:32 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}

/*
void test(unsigned int i, char *str)
{
	i = 32;
	if (*str >= 'a' && *str <= 'z')
		*str = *str - i;
}

int main(void)
{
	char str1[9] = "up we go";
	
	ft_striteri(str1, test);
	printf("%s", str1);
}
*/
