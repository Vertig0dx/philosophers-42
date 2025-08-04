/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:23:12 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/10/23 15:54:22 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
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
	ft_lstadd_front (&list3, list2);
	ft_lstadd_front (&list2, list1);
	printf("%s\n", (char *) list1->content);
	printf("%s\n", (char *) list1->next->content);
	printf("%s\n", (char *) list1->next->next->content);
}
*/
