/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:23:12 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/10/23 13:44:25 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
		return ;
	if (lst != NULL && *lst != NULL)
	{
		ft_lstclear(&(*lst)->next, del);
		ft_lstdelone(*lst, del);
		*lst = NULL;
	}
}

/*
void del (void *content)
{
	//free(content);
	content = NULL;
}

int main(void)
{
	t_list *list1;
	t_list *list2;
	t_list *list3;
	t_list *list4;
	t_list	*listfront;

	list1 = ft_lstnew("123");
	list2 = ft_lstnew("456");
	list3 = ft_lstnew("789");
	list4 = ft_lstnew("0");
	listfront = NULL;
	ft_lstadd_front(&listfront, list4);
	ft_lstadd_back(&list4, list1);
	ft_lstadd_back(&list1, list2);
	ft_lstadd_back(&list2, list3);
	ft_lstclear(&list2, &del);
	printf("%s\n", (char *) list4->content);
	printf("%s\n", (char *) list4->next->content);
	printf("%s\n", (char *) list4->next->next->content);
	printf("%s\n", (char *) list4->next->next->next->content);
	return (0);
}
*/