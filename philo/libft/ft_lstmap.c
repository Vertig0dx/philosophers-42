/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:23:12 by lmiguel-          #+#    #+#             */
/*   Updated: 2023/10/24 12:27:50 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*temp;

	newlist = NULL;
	while (lst != NULL)
	{
		temp = ft_lstnew((*f)(lst->content));
		if (temp == NULL)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, temp);
		lst = lst->next;
	}
	return (newlist);
}

/*
void *uppercase(void *content)
{
	char *str = (char *)content;
	char *str2 = ft_strdup(str);
	int i;
	
	i = 0;
	while (str2[i])
	{
		str2[i] = str2[i] - 48;
		i++;
	}
	return (str2);
}

void del(void *content)
{
	free(content);
}

int main(void)
{
	t_list *list1;
	t_list *list2;
	t_list *list3;
	t_list *list4;

	list1 = ft_lstnew("b");
	list2 = ft_lstnew("c");
	list3 = ft_lstnew("d");
	list4 = ft_lstnew("a");
	ft_lstadd_front(&list1, list4);
	ft_lstadd_back(&list1, list2);
	ft_lstadd_back(&list2, list3);
	printf("%s\n", (char *) list1->content);
	printf("%s\n", (char *) list1->next->content);
	printf("%s\n", (char *) list1->next->next->content);
	printf("%s\n", (char *) list4->content);
	ft_lstmap(list1, uppercase, del);
	printf("%s\n", (char *) list1->content);
	printf("%s\n", (char *) list1->next->content);
	printf("%s\n", (char *) list1->next->next->content);
	printf("%s\n", (char *) list4->content);
	return (0);
}
*/