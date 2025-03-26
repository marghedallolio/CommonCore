/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npezzati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:38:30 by npezzati          #+#    #+#             */
/*   Updated: 2024/11/25 17:38:35 by npezzati         ###   ########.fr       */
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
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
/*
int	main(void)
{
	const char	*str = "adesso sono stressata";
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
