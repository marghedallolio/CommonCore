/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:18:10 by mdalloli          #+#    #+#             */
/*   Updated: 2024/11/27 11:18:12 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void	print_content(void *content)
{
	printf("%s\n", (char *)content);
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
	
	printf("lista originale\n");
	print_list(lst);
	printf("ft_lstiter con print_content: \n");
	ft_lstiter(node1, print_content);
	
	ft_lstiter(node1, free);
	free(node2);
	free(node3);
	return (0);
}*/
