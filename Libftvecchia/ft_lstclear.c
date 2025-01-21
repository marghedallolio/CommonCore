/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:13:50 by mdalloli          #+#    #+#             */
/*   Updated: 2024/11/27 11:13:52 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
/*
void	del_function(void *content)
{
	free(content);
}

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL \n");
}

int	main(void)
{
	char	*str1 = "primo nodo";
	char	*str2 = "secondo nodo";
	char	*str3 = "terzo nodo";
	t_list	*node1 = ft_lstnew(str1);
	t_list	*node2 = ft_lstnew(str2);
	t_list	*node3 = ft_lstnew(str3);
	t_list	*lst;
	
	node1->next = node2;
	node2->next = node3;
	lst = node1;
	printf("lista prima della cancellazione \n");
	print_list(lst);
	ft_lstclear(&lst, del_function);
	printf("lista dopo la cancellazione: \n");
	if (!lst)
		printf("NULL(lista vuota)\n");
	else
		print_list(lst);
	return (0);
}*/
