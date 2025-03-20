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

/*seleziona il nodo piu' economico dallo stack a e lo sposta in b
allineando lo stack prima del push*/
void	push_cheapest_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->abv_median && cheapest_node->target->abv_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->abv_median)
		&& !(cheapest_node->target->abv_median))
		reverse_rotate_both(a, b, cheapest_node);
	align_for_push(a, cheapest_node, 'a');
	align_for_push(b, cheapest_node->target, 'b');
	pb(b, a, false);
}

/*sposta il valore minimo in cima in base alla posizione rispetto alla mediana*/
void	min_on_top(t_stack_node **a)
{
	t_stack_node	*min_node;

	min_node = find_min(*a);
	while ((*a)->value != min_node->value)
	{
		if (min_node->abv_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

/*assegna un indice a ogni nodo della lista e 
determina se e' sopra o sotto la mediana*/
void	mark_median_position(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_lenght(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->abv_median = true;
		else
			stack->abv_median = false;
		stack = stack->next;
		i++;
	}
}

t_stack_node	*stack_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	stack_lenght(t_stack_node *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
