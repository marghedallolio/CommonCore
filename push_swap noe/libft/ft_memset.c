/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npezzati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:35:45 by npezzati          #+#    #+#             */
/*   Updated: 2024/11/25 17:35:50 by npezzati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	value;
	size_t			i;

	i = 0;
	p = (unsigned char *)s;
	value = (unsigned char) c;
	while (i < n)
	{
		p[i] = value;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	char	buff[20] = "basta ciao";
	printf("buffer originale: %s\n", buff);
	ft_memset(buff, '*', 5);
	printf("buffer dopo: %s\n", buff);
	return (0);
}*/
