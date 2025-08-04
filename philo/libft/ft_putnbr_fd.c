/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:12:07 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/10/20 13:50:41 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write (fd, "-2147483648", 11);
			return ;
		}
		write (fd, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd ((n / 10), fd);
		ft_putnbr_fd ((n % 10), fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}
/*
int	main(void)
{
	int	min = -2147483648;
	int	max = 2147483647;
	ft_putnbr_fd (min, 1);
	ft_putchar_fd ('\n', 1);
	ft_putnbr_fd (max, 1);
	return (0);
}
*/
