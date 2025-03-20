/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:38:11 by mdalloli          #+#    #+#             */
/*   Updated: 2025/03/11 15:38:13 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*nxt;
	int				tmp;
	int				i;

	if (stack_lenght(*stack) < 2)
		return (-1);
	head = *stack;
	nxt = head->next;
	if (!head || !nxt)
	{
		ft_putendl_fd("Errore swap", 1);
		exit(0);
	}
	tmp = head->value;
	i = head->index;
	head->value = nxt->value;
	head->index = nxt->index;
	nxt->value = tmp;
	nxt->index = i;
	return (0);
}

void	sa(t_stack_node **a, bool print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}
