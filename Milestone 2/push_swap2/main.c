/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:00:49 by mdalloli          #+#    #+#             */
/*   Updated: 2025/02/24 14:00:50 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_a(a, b);
	set_cheapest(a);
}

void	append_node(t_stack_node **stack, int n)
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
		last_node = ft_lstlast(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack(t_stack_node **a, char **argv)
{
	int	n;
	int	i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i])) // da implementare
			free_error(a); // da implementare 
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_error(a);
		if (error_dup(*a, (int)n)) // da implemenatare
			free_error(a);
		append_node(a, (int)n);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' '); // vedere se split libft funziona
	init_stack(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			sa(&a, false);
		else if (ft_lstsize(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a); // da implementare
	return (0);
}

