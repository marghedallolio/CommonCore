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

#include "libft_printf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	slen;
	size_t	sublen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	sublen = slen - start;
	if (sublen > len)
		sublen = len;
	dest = (char *)malloc(sizeof(char) * (sublen + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < sublen)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int main(void)
{
	char *string = "Hello, world!";
	char *result;

	result = ft_substr(string, 7, 5);
	if (result)
	{
		printf("Originale: %s, Inizio: %u, Lunghezza: %zu, 
				Risultato: %s\n", string, 7, 5, result);
		free(result);
	}
	return (0);
}*/
