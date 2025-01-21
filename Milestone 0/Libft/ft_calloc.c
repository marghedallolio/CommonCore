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
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
/*
int	main(void)
{
	int	*array;
	int	i;
	
	i = 0;	
	array = (int *)ft_calloc(5, sizeof(int));
	
	if(!array)
		return (0);
	
	while(i < 5)
	{
		printf("%d, ", array[i]);
		i++;
	}
	return (0);
}*/
