/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:38:44 by mdalloli          #+#    #+#             */
/*   Updated: 2025/03/11 15:38:48 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack_node **s_to, t_stack_node **s_from)
{
	t_stack_node	*tmp;

	tmp = *s_from;
	*s_from = (*s_from)->next;
	if (*s_from)
		(*s_from)->prev = NULL;
	tmp->next = *s_to;
	tmp->prev = NULL;
	if (*s_to)
		(*s_to)->prev = tmp;
	*s_to = tmp;
	return (0);
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}

void	align_for_push(t_stack_node **stack, t_stack_node *top_node,
			char stack_name)
{
	while (stack_name == 'a' && *stack != top_node)
	{
		if (top_node->abv_median)
			ra(stack, false);
		else
			rra(stack, false);
	}
	while (stack_name == 'b' && *stack != top_node)
	{
		if (top_node->abv_median)
			rb(stack, false);
		else
			rrb(stack, false);
	}
}
