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
    if (stack->size < 2)
        return;
    t_node *first = stack->top;
    t_node *second = first->next;
    first->next = second->next;
    second->next = first;
    stack->top = second;
}

// push (pa, pb)
void push_to(t_stack *src, t_stack *dest)
{
    if (src->size == 0)
        return;
    int value = pop(src);
    push(dest, value);
}

// rotate (ra, rb, rr)
void rotate(t_stack *stack)
{
    if (stack->size < 2)
        return;
    t_node *first = stack->top;
    t_node *last = first;
    while (last->next)
        last = last->next;
    stack->top = first->next;
    first->next = NULL;
    last->next = first;
}

// reverse rotate (rra, rrb, rrr)
void reverse_rotate(t_stack *stack)
{
    if (stack->size < 2)
        return;
    t_node *prev = NULL;
    t_node *current = stack->top;
    while (current->next)
    {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    current->next = stack->top;
    stack->top = current;
}