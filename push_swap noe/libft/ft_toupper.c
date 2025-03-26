/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npezzati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:42:31 by npezzati          #+#    #+#             */
/*   Updated: 2024/11/25 17:43:11 by npezzati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
/*
int main(void)
{
    char c1 = 'a';
    char c2 = 'z';
    char c3 = 'A';
    char c4 = '1';
    char c5 = '!';

    printf("Originale: '%c' -> Nuova: '%c'\n", c1, ft_toupper(c1));
    printf("Originale: '%c' -> Nuova: '%c'\n", c2, ft_toupper(c2));
    printf("Originale: '%c' -> Nuova: '%c'\n", c3, ft_toupper(c3));
    printf("Originale: '%c' -> Nuova: '%c'\n", c4, ft_toupper(c4));
    printf("Originale: '%c' -> Nuova: '%c'\n", c5, ft_toupper(c5));

    return (0);
}*/
