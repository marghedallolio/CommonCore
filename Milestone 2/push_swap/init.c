/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:09:29 by mdalloli          #+#    #+#             */
/*   Updated: 2025/03/19 15:09:31 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*nizializza una lista t_stack_node partendo da un array di stringhe argv*/
void	init_stack(t_stack_node **a, char **argv, int argc)
{
	long int	n;
	int			i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_error(a, argc, argv);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_error(a, argc, argv);
		if (error_dup(*a, (int)n))
			free_error(a, argc, argv);
		stack_add_back(a, (int)n);
		i++;
	}
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	mark_median_position(a);
	mark_median_position(b);
	set_target_a(a, b);
	cost_a(a, b);
	set_cheapest(a);
}

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	mark_median_position(a);
	mark_median_position(b);
	set_target_b(a, b);
}

/*aggiunge un nuovo nodo in fondo alla lista t_stack_node*/
void	stack_add_back(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->value = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = stack_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}
