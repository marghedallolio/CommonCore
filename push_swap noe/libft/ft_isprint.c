/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npezzati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:34:04 by npezzati          #+#    #+#             */
/*   Updated: 2024/11/25 17:34:09 by npezzati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	int	r;

	r = 0;
	if (c >= 32 && c <= 126)
	{
		r = 1;
	}
	return (r);
}
/*
int	main(void)
{
	char test[] = {'A', 'z', '\t', '9', '!'};
	int	numtest = sizeof(test) / sizeof(test[0]);
	int	i;
	char	c;
	
	i = 0;
	while (i < numtest)
	{
		char c = test[i];
		printf("Test del carattere: '%c' (%d): %s\n",c ,c , 
				ft_isprint(c) ? "printable" : "Non printable");
		i++;
	}
	return (0);
}*/
