/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npezzati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:41:43 by npezzati          #+#    #+#             */
/*   Updated: 2024/11/27 13:41:46 by npezzati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

void	ft_lstdelone(t_node *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->value);
	free(lst);
}
/*void del_content(void *content) {
    free(content);
}

void ft_printlst(t_list *lst) {
    while (lst) {
        printf("%s -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

int main() {
    t_list *head = ft_lstnew(strdup("t_node 1"));
    t_list *node2 = ft_lstnew(strdup("t_node 2"));
    t_list *node3 = ft_lstnew(strdup("t_node 3"));

    head->next = node2;
    node2->next = node3;
    
    printf("Lista prima della cancellazione:\n");
    ft_printlst(head);

    head->next = node3;

    printf("\nLista dopo la cancellazione:\n");
    ft_printlst(head);
    free(head);
	free(node2);
	free(node3);
    return 0;
}*/
