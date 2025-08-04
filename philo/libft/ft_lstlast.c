/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:23:12 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/10/18 17:09:05 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
int	main(void)
{
	t_list *list1;
	t_list *list2;
	t_list *list3;
	t_list	*listfront;

	list1 = ft_lstnew("123");
	list2 = ft_lstnew("456");
	list3 = ft_lstnew("789");
	listfront = NULL;
	ft_lstadd_front (&listfront, list3);
	ft_lstadd_front (&listfront, list2);
	ft_lstadd_front (&listfront, list1);
	printf("%s\n",(char *) ft_lstlast(list1)->content);
}
*/
