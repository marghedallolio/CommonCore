/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:04:10 by mdalloli          #+#    #+#             */
/*   Updated: 2024/11/19 11:04:14 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (n == 0)
		return (dest);
	if (!dest && !src)
		return (NULL);
	i = 0;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char src1[] = "Hello, world!";
	char dest1[20];
	printf("Test 1: Copia di una stringa\n");
	printf("Sorgente: '%s'\n", src1);
	ft_memcpy(dest1, src1, strlen(src1) + 1);
	printf("Destinazione dopo memcpy: '%s'\n", dest1);
	return (0);
}*/
