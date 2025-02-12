/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:04:38 by mdalloli          #+#    #+#             */
/*   Updated: 2024/11/26 17:04:39 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
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
	int	size;
	
	node1->next = node2;
	node2->next = node3;
	lst = node1;
	print_list(lst);
	size = ft_lstsize(lst);
	printf("la dimensione della lista e': %d\n", size);
	free(node1);
	free(node2);
	free(node3);
	return (0);
}*/
