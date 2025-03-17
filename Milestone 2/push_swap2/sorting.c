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

void	sort_three(t_stack_node **a)
{
	t_stack_node	*big;

	big = find_max(*a);  //da implementare
	if (big == *a)
		ra(a, false);
	else if ((*a)->next == big)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	currente_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if(!stack)
		return ;
	median = ft_lstsize(stack) / 2;
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

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = ft_lstsize(*a);
	if(len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if(len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes(*a, *b);
		move_a_to_b(*a, *b); //da implementare
	}
	sort_three(a);
	while(*b)
	{
		init_nodes(*a, *b);
		move_b_to_a(a, b); //dsa implentare
	}
	current_index(*a);
	min_on_top(a); // da implentare
}
