/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npezzati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:16:09 by npezzati          #+#    #+#             */
/*   Updated: 2024/11/27 10:16:14 by npezzati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*void ft_printlst(t_list *lst)
{
	while(lst){
		printf("%s ->", (char *)lst->content);
		lst = lst->next;
		}
	printf("NULL\n");
}
int main(){
	char *s3 = "ciao";
	char *s1 = "hei";
	char *s2= "tu";
	t_list *head = ft_lstnew(s1);
	t_list *node2 = ft_lstnew(s2);
	t_list *node3 = ft_lstnew(s3);
	
	head->next = node2;
	ft_lstadd_back(&head, node3);
	
	ft_printlst(head);
	free(head);
	free(node2);
	free(node3);
	return 0;
}*/
