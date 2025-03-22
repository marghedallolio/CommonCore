/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:10:49 by mdalloli          #+#    #+#             */
/*   Updated: 2025/03/19 15:10:50 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*assegna un target alla stack a*/
void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current;
	t_stack_node	*target_node;
	long			best_match;

	while (a)
	{
		best_match = LONG_MIN;
		current = b;
		while (current)
		{
			if (current->value < a->value && current->value > best_match)
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

/*assegna un target alla stack b*/
void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current;
	t_stack_node	*target_node;
	long			best;

	while (b)
	{
		best = LONG_MAX;
		current = a;
		while (current)
		{
			if (current->value > b->value && current->value < best)
			{
				best = current->value;
				target_node = current;
			}
			current = current->next;
		}
		if (best == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

/*calcola il costo di push per ogni nodo dello stack a 
in base alla sua posizione rispetto alla mediana*/
void	cost_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_lenght(a);
	len_b = stack_lenght(b);
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

/*imposta il campo cheapest del nodo con il costo di push minimo*/
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

/*trova il nodo con il costo minimo di push nello stack a*/
t_stack_node	*get_cheapest(t_stack_node *a)
{
	t_stack_node	*current;
	t_stack_node	*cheapest;
	int				min_cost;

	if (!a)
		return (NULL);
	current = a;
	cheapest = a;
	min_cost = a->push_cost;
	while (current)
	{
		if (current->push_cost < min_cost)
		{
			min_cost = current->push_cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}
