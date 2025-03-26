/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npezzati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:32:42 by npezzati          #+#    #+#             */
/*   Updated: 2024/11/25 17:32:50 by npezzati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	int	r;

	r = 0;
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
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
				ft_isalpha(c) ? "lettera" : "Non lettera");
		i++;
	}
	return (0);
}*/
