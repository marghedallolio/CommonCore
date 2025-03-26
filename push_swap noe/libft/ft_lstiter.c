/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npezzati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:42:34 by npezzati          #+#    #+#             */
/*   Updated: 2024/11/27 13:42:36 by npezzati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

void	ft_lstiter(t_node *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->value);
		lst = lst->next;
	}
}
/*t_list *ft_lstnew(void *content) {
    t_list *new_node;

    new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return (NULL);

    new_node->content = content;
    new_node->next = NULL;
    return (new_node);
}

void del_content(void *content) {
    free(content);
}

void *to_lowercase(void *content) {
    char *str = (char *)content;
    char *lower_str = strdup(str);
    if (!lower_str)
        return NULL;

    for (int i = 0; lower_str[i]; i++) {
        if (lower_str[i] >= 'A' && lower_str[i] <= 'Z')
            lower_str[i] += 32;
    }

    return (void *)lower_str;
}

void print_list(t_list *lst) {
    while (lst) {
        printf("%s -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

int main() {
    t_list *head = ft_lstnew(strdup("HELLO"));
    t_list *node2 = ft_lstnew(strdup("WORLD"));
    t_list *node3 = ft_lstnew(strdup("TEST"));
    head->next = node2;
    node2->next = node3;

    printf("Lista originale:\n");
    print_list(head);

    t_list *new_list = ft_lstmap(head, to_lowercase, del_content);

    printf("\nTransformer:\n");
    print_list(new_list);

    ft_lstiter(head, del_content);
    ft_lstiter(new_list, del_content);
	free(head);
	free(node2);
	free(node3);
    return 0;
}*/
