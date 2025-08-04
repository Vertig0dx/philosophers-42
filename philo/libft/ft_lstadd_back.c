/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:23:12 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/12/21 14:14:12 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*old;

	if (lst == NULL || new == NULL)
		return ;
	old = ft_lstlast(*lst);
	if (old == NULL)
		*lst = new;
	else
		old->next = new;
}
/*
int	main(void)
{
	t_list *list1;
	t_list *list2;
	t_list *list3;

	list1 = ft_lstnew("123");
	list2 = ft_lstnew("456");
	list3 = ft_lstnew("789");
	ft_lstadd_back (&list1, list2);
	ft_lstadd_back (&list1, list3);
	printf("%s\n", (char *) list1->content);
	printf("%s\n", (char *) list1->next->content);
	printf("%s\n", (char *) list1->next->next->content);
	printf("%s\n", (char *) ft_lstlast(list1)->content);
}*/
