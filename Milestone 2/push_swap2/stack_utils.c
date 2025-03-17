/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:15:08 by mdalloli          #+#    #+#             */
/*   Updated: 2025/03/17 17:15:12 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return(1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current;
	t_stack_node	*target_node;
	long			best_match;

	while(a)
	{
		best_match = LONG_MIN;
		current = b;
		while (current)
		{
			if (current->value < a->value 
				&& current->value > best_match)
			{
				best_match = current->value;
				target_node = current;
			}
			current = current->next;
		}
		if (best_match == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

void	cost_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->abv_median))
			a->push_cost = len_a - (a->index);
		if (a->target->abv_median)
			a->push_cost += a->target->index;
		else
			a->push_cost += len_b - (a->target->index);
		a = a->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	long			cheapest_val;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_val = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_val)
		{
			cheapest_val = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}