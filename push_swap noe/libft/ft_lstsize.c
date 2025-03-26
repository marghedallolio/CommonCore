/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npezzati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:02:56 by npezzati          #+#    #+#             */
/*   Updated: 2024/11/27 11:03:01 by npezzati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_node *lst)
{
	int		count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
/*void ft_printlst(t_list *lst) {
    while (lst) {
        printf("%s -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}
int main() {
    t_list *head = ft_lstnew("salsa");
    t_list *node2 = ft_lstnew("di");
    t_list *node3 = ft_lstnew("soia");
    head->next = node2;
    node2->next = node3;

    printf("Lista collegata:\n");
    ft_printlst(head);

    int size = ft_lstsize(head);
    printf("\nDimensione della lista: %d\n", size);

    free(node3);
    free(node2);
    free(head);

  return 0;
}
*/
