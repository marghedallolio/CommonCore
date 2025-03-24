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

// errors
int				error_syntax(char *str);
int				error_dup(t_stack_node *a, int n);
void			free_error(t_stack_node **a, int argc, char **str);
void			free_stack(t_stack_node **a);
void			free_arr(char **arr);

// init
void			init_stack(t_stack_node **a, char **argv, int argc);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			stack_add_back(t_stack_node **stack, int n);

// stack utils
void			push_cheapest_to_b(t_stack_node **a, t_stack_node **b);
void			min_on_top(t_stack_node **a);
void			mark_median_position(t_stack_node *stack);
t_stack_node	*stack_last(t_stack_node *stack);
int				stack_lenght(t_stack_node *stack);

// swap
int				swap(t_stack_node **stack);
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);

//push
int				push(t_stack_node **s_to, t_stack_node **s_from);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);
void			align_for_push(t_stack_node **stack, t_stack_node *top_node,
					char stack_name);

//rotate
int				rotate(t_stack_node **stack);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);

// reverse rotate
int				reverse_rotate(t_stack_node **stack);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			reverse_rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);

// sorting
bool			stack_sorted(t_stack_node *stack);
void			sort_three(t_stack_node **a);
void			sort_stack(t_stack_node **a, t_stack_node **b);

// target_cost
void			set_target_a(t_stack_node *a, t_stack_node *b);
void			set_target_b(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *stack);
void			cost_a(t_stack_node *a, t_stack_node *b);
t_stack_node	*get_cheapest(t_stack_node *a);

//utils
void			stampa_stack(t_stack_node *stack, char *name);
long			ft_atol(const char *s);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

#endif
