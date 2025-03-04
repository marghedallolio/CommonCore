/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:00:10 by mdalloli          #+#    #+#             */
/*   Updated: 2025/02/24 14:00:11 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap (sa, sb, ss)
void swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

// push (pa, pb)
void push_to(t_stack *src, t_stack *dest)
{
	int	value;
	if (!src || src->size == 0)
		return;
	value = pop(src);
	push(dest, value);
}

// rotate (ra, rb, rr)
void rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || stack->size < 2)
		return;
	first = stack->top;
	stack->top = first->next;
	last = first;
	while (last->next)
		last = last->next;
	first->next = NULL;
	last->next = first;
}

// reverse rotate (rra, rrb, rrr)
void reverse_rotate(t_stack *stack)
{
	t_node	*prev;
	t_node	*current;

	if (!stack || stack->size < 2)
		return;
	prev = NULL;
	current = stack->top;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = stack->top;
	stack->top = current;
}