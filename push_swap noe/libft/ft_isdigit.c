/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npezzati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:33:43 by npezzati          #+#    #+#             */
/*   Updated: 2024/11/25 17:33:49 by npezzati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	int	r;

	r = 0;
	if (c >= 48 && c <= 57)
	{
		r = 1;
	}
	return (r);
}
/*
int	main(void)
{
	char test[] = {'A', 'z', '0', '9', '!'};
	int	numtest = sizeof(test) / sizeof(test[0]);
	int	i;
	char	c;
	
	i = 0;
	while (i < numtest)
	{
		char c = test[i];
		printf("Test del carattere: '%c' (%d): %s\n",c ,c , 
				ft_isdigit(c) ? "numero" : "Non numero");
		i++;
	}
	return (0);
}*/
