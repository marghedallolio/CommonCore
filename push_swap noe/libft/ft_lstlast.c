/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npezzati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:12:36 by npezzati          #+#    #+#             */
/*   Updated: 2024/11/27 11:12:39 by npezzati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*void ft_printlst(t_list *lst);
{
	while(lst){
		printf("%s ->", (char *)lst->content);
		lst = lst->next;
		}
	printf("NULL\n");
}

int main() {
    t_list *head = ft_lstnew("ciao");
    t_list *node2 = ft_lstnew("sono");
    t_list *node3 = ft_lstnew("shrek");
    head->next = node2;
    node2->next = node3;
    
    printf("Lista completa:\n");
    ft_printlst(head);

    t_list *last = ft_lstlast(head);

    printf("\nUltimo t_node: %s\n", (char *)last->content);
    
    free(node3);
    free(node2);
    free(head);

    return 0;
}*/
