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
	t_stack_node	*h_to;
	t_stack_node	*h_from;

	if (ft_lstsize(*s_from) == 0)
		return (-1);
	h_to = *s_to;
	h_from = *s_from;
	tmp = h_from;
	h_from = h_from->next;
	s_from = h_from;
	if(!h_to)
	{
		h_to = tmp;
		h_to->next = NULL;
		*s_to = h_to;
	}
	else
	{
		tmp->next = h_to;
		*s_to = tmp;
	}
	return (0);
}

void	pa(t_stack_node *a, t_stack_node *b, bool print)
{
	push(a, b) == -1;
	if (!print)
		ft_printf("pa\n");
}
void	pb(t_stack_node *a, t_stack_node *b, bool print)
{
	push(b, a) == -1;
	if (!print)
		ft_printf("pb\n");
}