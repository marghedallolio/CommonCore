/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:20:45 by mdalloli          #+#    #+#             */
/*   Updated: 2024/11/18 17:20:49 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}
/*
int main(void)
{
    char c1 = 'A';
    char c2 = 'z';
    char c3 = 'A';
    char c4 = '1';
    char c5 = '!';

    printf("Originale: '%c' -> Nuova: '%c'\n", c1, ft_tolower(c1));
    printf("Originale: '%c' -> Nuova: '%c'\n", c2, ft_tolower(c2));
    printf("Originale: '%c' -> Nuova: '%c'\n", c3, ft_tolower(c3));
    printf("Originale: '%c' -> Nuova: '%c'\n", c4, ft_tolower(c4));
    printf("Originale: '%c' -> Nuova: '%c'\n", c5, ft_tolower(c5));

    return (0);
}*/
