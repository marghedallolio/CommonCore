/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:17:12 by mdalloli          #+#    #+#             */
/*   Updated: 2025/02/24 14:17:13 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// inizializzazione dello stack (vuoto)
t_stack *init_stack(void)
{
    t_stack *stack;

    stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->top = NULL;
    stack->size = 0;
    return (stack);
}

// inserimento un elemento in cima allo stack
void push(t_stack *stack, int value)
{
    t_node *new_node;

	if (!stack)
		return ;
    new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return;
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

// rimozione e restituzione del valore in cima allo stack
int pop(t_stack *stack)
{
    int value;
    t_node *temp;

    if (!stack || stack->size == 0)
        return (INT_MIN);
    temp = stack->top;
    value = temp->value;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return (value);
}

// liberazione memoria dello stack
void free_stack(t_stack *stack)
{
    t_node *temp;

	if (!stack)
		return ;
    while (stack->top)
    {
        temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
    free(stack);
}
