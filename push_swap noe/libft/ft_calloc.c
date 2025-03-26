/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npezzati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:32:18 by npezzati          #+#    #+#             */
/*   Updated: 2024/11/25 17:32:24 by npezzati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
/*
int main(void)
{
	size_t nmemb2 = 3;
	size_t size2 = sizeof(char);
	char *arr2 = ft_calloc(nmemb2, size2);

	printf("\nTest 2: Allocazione di 3 char (0 inizializzati)\n");
	if (arr2)
	{
		for (size_t i = 0; i < nmemb2; i++)
			printf("arr2[%zu] = '%c' (ascii: %d)\n", i, arr2[i], arr2[i]);
		free(arr2);
	}
	else
		printf("Errore nell'allocazione della memoria.\n");
	return (0);
}*/
