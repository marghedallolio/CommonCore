/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:16:59 by mdalloli          #+#    #+#             */
/*   Updated: 2025/03/17 11:36:18 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*verifica se lo stack e' ordinato in ordine crescente*/
bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

/*sorta uno stack di tre elementi*/
void	sort_three(t_stack_node **a)
{
	t_stack_node	*big;

	big = find_max(*a);
	if (big->value == (*a)->value)
		ra(a, false);
	else if ((*a)->next->value == big->value)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int	len_a;
	int	len_b;

	len_a = stack_lenght(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		push_cheapest_to_b(a, b);
	}
	len_b = stack_lenght(*b);
	sort_three(a);
	while (len_b > 0)
	{
		init_nodes_b(*a, *b);
		align_for_push(a, (*b)->target, 'a');
		pa(a, b, false);
		len_b = stack_lenght(*b);
	}
	mark_median_position(*a);
	min_on_top(a);
}
