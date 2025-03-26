/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npezzati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:35:25 by npezzati          #+#    #+#             */
/*   Updated: 2024/11/25 17:35:29 by npezzati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (n == 0)
		return (dest);
	if (!dest && !src)
		return (NULL);
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = ((const char *)src)[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			((char *)dest)[i - 1] = ((const char *)src)[i - 1];
			i--;
		}
	}
	return (dest);
}
/*
int main()
{
    char str[] = "ciao, nintoiydh!";
    printf("stringa originale: %s\n", str);
    ft_memmove(str + 7, str + 6, 6);
    printf("Result: %s\n", str);
    return 0;
}*/
