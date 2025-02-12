/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:04:21 by mdalloli          #+#    #+#             */
/*   Updated: 2024/11/19 16:04:23 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	i = 0;
	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	buff1[] = "ciao, ciao";
	char	buff2[] = "ciao, ciao";
	char	buff3[] = "ciao, addio";
	size_t	n;
	
	n = 10;
	printf("Comparazione tra %s e %s per %zu bytes: %d\n", buff1, buff2, n, 
			ft_memcmp(buff1, buff2, n));
	
	n = 11;
	printf("Comparazione tra %s e %s per %zu bytes: %d\n", buff2, buff3, n, 
			ft_memcmp(buff2, buff3, n));
}*/
