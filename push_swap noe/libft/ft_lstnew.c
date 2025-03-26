/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npezzati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:42:26 by npezzati          #+#    #+#             */
/*   Updated: 2024/11/26 15:42:30 by npezzati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>

t_node	*ft_lstnew(void *content)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = content;
	new_node->next = NULL;
	return (new_node);
}
/*
void ft_printlst(t_list *lst);
{
	while(lst){
		printf("%s ->", (char *)lst->content);
		lst = lst->next;
		}
	printf("NULL\n");
}

int main(){
	char *s1 = "ciao";
	t_list *nuova_lista = ft_lstnew(s1);
	
	ft_printlst(nuova_lista);
	free(head);
	free(node2);
	free(node3);
	return 0;
}*/
