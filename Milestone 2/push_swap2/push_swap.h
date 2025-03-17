/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:00:17 by mdalloli          #+#    #+#             */
/*   Updated: 2025/02/24 14:00:19 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>
# include "libft_printf/libft_printf.h"

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					push_cost;
	int					abv_median;
	int					cheapest;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

// handle_error
// error_syntax
// free_error
// free_stack
// error_dup

// inizializzazione stack 
void	init_stack(t_stack_node **a, char **argv);
// inizializzazione node
void	init_nodes_a(t_stack_node *a, t_stack_node *b);
void	init_nodes_b(t_stack_node *a, t_stack_node *b);

// stack utils
void	append_node(t_stack_node **stack, int n);
void	set_target_a(t_stack_node *a, t_stack_node *b);
void	cost_a(t_stack_node *a, t_stack_node *b);
void	set_cheapest(t_stack_node *stack);
bool	stack_sorted(t_stack_node *stack);
long	ft_atol(const char *s);

//operations
int		swap(t_stack_node **stack);
void	sa(t_stack_node **a, bool print);
void	sb(t_stack_node **b, bool print);
void	ss(t_stack_node **a, t_stack_node **b, bool print);

int		push(t_stack_node **s_to, t_stack_node **s_from);
void	pa(t_stack_node *a, t_stack_node *b, bool print);
void	pb(t_stack_node *a, t_stack_node *b, bool print);

int		rotate(t_stack_node **stack);
void	ra(t_stack_node **a, bool print);
void	rb(t_stack_node **b, bool print);
void	rr(t_stack_node **a, t_stack_node **b, bool print);
void 	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);

int		reverse_rotate(t_stack_node **stack);
void	rra(t_stack_node **a, bool print);
void	rrb(t_stack_node **b, bool print);
void	rrr(t_stack_node **a, t_stack_node **b, bool print);

// sorting algorithm 
void	sort_three(t_stack_node **a);
void	currente_index(t_stack_node *stack);
void	sort_stack(t_stack_node **a, t_stack_node **b);

#endif
