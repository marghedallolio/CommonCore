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
#define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "libft_printf.h"

#define INT_MIN -2147483648
#define INT_MAX 2147483647

typedef struct s_node
{
    int             value;
    struct s_node   *next;
} t_node;

typedef struct s_stack
{
    t_node  *top;
    int     size;
} t_stack;


t_stack *init_stack(void);
void	push(t_stack *stack, int value);
void	free_stack(t_stack *stack);
void	swap(t_stack *stack);
void	push_to(t_stack *src, t_stack *dest);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	parse_input(t_stack *a, char **argv);
void	radix_sort(t_stack *a, t_stack *b);
int		pop(t_stack *stack);

#endif
