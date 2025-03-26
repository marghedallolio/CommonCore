/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npezzati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:42:08 by npezzati          #+#    #+#             */
/*   Updated: 2024/11/27 13:42:10 by npezzati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_node **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->value);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
/*void del_c(void *content){
	free(content);
}
void ft_printlst(t_list *lst)
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
	node2->next = node3;
	
	ft_lstclear(&head, del_c);	
	ft_printlst(head);
	free(head);
	free(node2);
	free(node3);
	return 0;
}*/
