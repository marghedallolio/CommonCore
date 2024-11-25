/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:48:53 by mdalloli          #+#    #+#             */
/*   Updated: 2024/11/19 11:48:56 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		else
			s++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	*str = "sono molto stanca";
	char	c1 = 'o';
	char	c2 = 's';
	char	c3 = 'g';
	
	char	*result = ft_strchr(str, c1);
	if (result)
		printf("stringa: %s, carattere: %c, risultato: %s\n", str, c1, result);
	else
		printf("stringa: %s, carattere: %c, risultato: non trovato \n", str, c1);
		
	result = ft_strchr(str, c2);
	if (result)
		printf("stringa: %s, carattere: %c, risultato: %s\n", str, c2, result);
	else
		printf("stringa: %s, carattere: %c, 
				risultato: non trovato \n", str, c2);	
		
	result = ft_strchr(str, c3);
	if (result)
		printf("stringa: %s, carattere: %c, risultato: %s\n", str, c3, result);
	else
		printf("stringa: %s, carattere: %c, risultato: non trovato \n", str, c3);
	return (0);
}*/
