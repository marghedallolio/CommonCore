/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:00:35 by mdalloli          #+#    #+#             */
/*   Updated: 2025/02/24 14:00:36 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int is_number(char *str)
{
    int i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int is_duplicate(t_stack *stack, int num)
{
    t_node *current = stack->top;
    while (current)
    {
        if (current->value == num)
            return (1);
        current = current->next;
    }
    return (0);
}

void parse_input(t_stack *a, char **argv)
{
    int num;
    for (int i = 1; argv[i]; i++)
    {
        if (!is_number(argv[i]))
        {
            write(2, "Error\n", 6);
            exit(EXIT_FAILURE);
        }
        num = atoi(argv[i]);
        if (num < INT_MIN || num > INT_MAX || is_duplicate(a, num))
        {
            write(2, "Error\n", 6);
            exit(EXIT_FAILURE);
        }
        push(a, num);
    }
}