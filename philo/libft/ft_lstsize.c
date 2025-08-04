/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:23:12 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/10/20 15:53:31 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 1;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
int main(void)
{
	t_list	*lst1;
	t_list	*lst2;
	t_list	*lst3;
	lst1 = ft_lstnew("123");
	lst2 = ft_lstnew("456");
	lst3 = ft_lstnew("789");
	ft_lstadd_front(&lst3, lst2);
	ft_lstadd_front(&lst2, lst1);
	printf("%d\n", ft_lstsize(lst2));
}*/
