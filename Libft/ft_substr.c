/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:13:15 by mdalloli          #+#    #+#             */
/*   Updated: 2024/11/22 10:13:18 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((i < n) && (src[i] != '\0'))
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;
	size_t	alen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_calloc(1, sizeof(char)));
	if (slen - start < len)
		alen = slen - start;
	else
		alen = len;
	substr = (char *)malloc((alen + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	ft_strncpy(substr, (s + start), alen);
	substr[alen] = '\0';
	return (substr);
}
/*
int main(void)
{
	char *string = "Hello, world!";
	char *result;

	printf("Testing ft_substr:\n");

	// Caso 1: Sottostringa normale
	result = ft_substr(string, 7, 5);
	if (result)
	{
		printf("Originale: %s, Inizio: %u, Lunghezza: %zu, Risultato: %s\n", string, 7, 5, result);
		free(result);
	}

	// Caso 2: Start oltre la lunghezza della stringa
	result = ft_substr(string, 20, 5);
	if (result)
	{
		printf("Originale: %s, Inizio: %u, Lunghezza: %zu, Risultato: %s\n", string, 20, 5, result);
		free(result);
	}

	// Caso 3: Lunghezza maggiore della stringa rimanente
	result = ft_substr(string, 7, 50);
	if (result)
	{
		printf("Originale: %s, Inizio: %u, Lunghezza: %zu, Risultato: %s\n", string, 7, 50, result);
		free(result);
	}

	// Caso 4: Lunghezza zero
	result = ft_substr(string, 7, 0);
	if (result)
	{
		printf("Originale: %s, Inizio: %u, Lunghezza: %zu, Risultato: %s\n", string, 7, 0, result);
		free(result);
	}
	return (0);
}*/

