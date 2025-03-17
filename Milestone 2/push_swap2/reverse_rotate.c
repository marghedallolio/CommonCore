/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:38:30 by mdalloli          #+#    #+#             */
/*   Updated: 2025/03/11 15:38:39 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*tail;

	if(ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if(head->next->next == NULL)
		{
			head->next = NULL;
			break;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

void	rra(t_stack_node **a, bool print)
{
	reverse_rotate(a) == -1;
	if (!print)
		ft_printf("rra\n");
	return(0);
}

void	rrb(t_stack_node **b, bool print)
{
	reverse_rotate(b) == -1;
	if (!print)
		ft_printf("rrb\n");
	return(0);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!print)
		ft_printf("rrr\n");
	return (0);
}