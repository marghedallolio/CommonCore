/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npezzati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:41:45 by npezzati          #+#    #+#             */
/*   Updated: 2024/11/25 17:41:52 by npezzati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)s + len);
		len--;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char *str = "ciao, come va?";
	char ch = 'o';
	char *result;

	printf("Stringa originale: '%s'\n", str);
	printf("Carattere da cercare: '%c'\n\n", ch);

	result = ft_strrchr(str, ch);
	if (result)
		printf("Ultima occorrenza di '%c' trovata a posizione: %ld\n", 
				ch, result - str);
	else
		printf("Carattere '%c' non trovato nella stringa.\n", ch);
	return (0);
}*/
