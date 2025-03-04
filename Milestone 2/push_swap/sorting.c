/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:16:59 by mdalloli          #+#    #+#             */
/*   Updated: 2025/02/24 14:17:00 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Trova il numero massimo di bit necessari per il sorting
static int get_max_bits(t_stack *stack)
{
    int max = stack->size - 1; // Poiché usiamo gli indici normalizzati
    int bits = 0;

    while (max > 0) {
        max >>= 1;
        bits++;
    }
    return bits;
}

// Implementazione del Radix Sort in base 2 per push_swap
void radix_sort(t_stack *a, t_stack *b)
{
    int size = a->size;
    int max_bits = get_max_bits(a);

    for (int bit = 0; bit < max_bits; bit++) {
        int count = size;
        while (count--) {
            int num = a->top->value; // Prendi il valore in cima allo stack

            if (((num >> bit) & 1) == 0) {
                push_to(a, b); // Sposta in B se il bit è 0 (pb)
            } else {
                rotate(a); // Ruota in A (ra)
            }
        }
        while (b->size > 0) {
            push_to(b, a); // Riporta tutto in A (pa)
        }
    }
}
