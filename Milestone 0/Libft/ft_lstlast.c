/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:10:00 by mdalloli          #+#    #+#             */
/*   Updated: 2024/11/26 17:10:02 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
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
	char	*str1 = "primo nodo";
	char	*str2 = "secondo nodo";
	char	*str3 = "terzo nodo";
	t_list	*node1 = ft_lstnew(str1);
	t_list	*node2 = ft_lstnew(str2);
	t_list	*node3 = ft_lstnew(str3);
	t_list	*lst;
	t_list	*last_node;
	int	size;
	
	node1->next = node2;
	node2->next = node3;
	lst = node1;
	print_list(lst);
	last_node = ft_lstlast(lst);
	if (last_node)
		printf("l'ultimo nodo contiene: %s\n", (char *)last_node->content);
	else
		printf("la lista e' vuota \n");
	
	free(node1);
	free(node2);
	free(node3);
	return (0);
}*/
