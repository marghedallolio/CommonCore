/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:58:00 by mdalloli          #+#    #+#             */
/*   Updated: 2024/11/21 10:58:02 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	tot_size;
	void	*ptr;

	tot_size = nmemb * size;
	if (size != 0 && tot_size / size != nmemb)
		return (NULL);
	ptr = malloc(tot_size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, tot_size);
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
