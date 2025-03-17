/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:09:23 by mdalloli          #+#    #+#             */
/*   Updated: 2024/11/27 11:09:25 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
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
	ft_lstdelone(node2, del_function);
	node1->next = node3;
	printf("lista dopo la cancellazione: \n");
	printf(lst);
	ft_lstdelone(node1, del_function);
	ft_lstdelone(node3, del_function);
	return (0);
}*/
