/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:55:38 by mdalloli          #+#    #+#             */
/*   Updated: 2024/11/26 16:55:39 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
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
	char	*str1 = "secondo nodo";
	char	*str2 = "primo nodo";
	t_list	*node1;
	t_list	*node2;
	t_list	*lst;

	node1 = ft_lstnew(str1);
	node2 = ft_lstnew(str2);
	lst = node1;
	ft_lstadd_front(&lst, node2);
	printf("lista dopo l'aggiunta del nodo in testa: \n");
	print_list(lst);
	free(node1);
	free(node2);
	return (0);
}*/
