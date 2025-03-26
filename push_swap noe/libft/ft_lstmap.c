/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npezzati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:42:48 by npezzati          #+#    #+#             */
/*   Updated: 2024/11/27 13:42:51 by npezzati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdlib.h>
//#include <stdio.h>

/*void *duplicate_content(void *content) {
    char *str = (char *)content;
    return (strdup(str));
}

void del_content(void *content) {
    free(content);
}
*/
t_node	*ft_lstmap(t_node *lst, void *(*f)(void *), void (*del)(void *))
{
	t_node	*new_list;
	t_node	*new_node;
	void	*new_content;

	new_list = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->value);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/*
void print_list(t_list *lst) {
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

    printf("Original:\n");
    print_list(head);

    t_list *new_list = ft_lstmap(head, duplicate_content, del_content);

    printf("\nNew one:\n");
    print_list(new_list);

    ft_lstclear(&head, del_content);
    ft_lstclear(&new_list, del_content);
	free(head);
	free(node2);
	free(node3);
    return 0;
}*/
