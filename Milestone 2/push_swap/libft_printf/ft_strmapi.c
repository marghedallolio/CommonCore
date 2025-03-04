/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:11:16 by mdalloli          #+#    #+#             */
/*   Updated: 2024/11/22 14:11:17 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
/*
char	ft_alternate_case(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (c >= 'a' && c <= 'z') ? c - 32 : c;
	else
		return (c >= 'A' && c <= 'Z') ? c + 32 : c;
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*result;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[len] = '\0';
	return (result);
}
/*
int	main(void)
{
	const char *orig = "hello world!";
	char *mod;

	printf("Stringa originale: '%s'\n", orig);

	mod = ft_strmapi(orig, ft_alternate_case);
	if (!mod)
	{
		fprintf(stderr, "Errore nella funzione ft_strmapi.\n");
		return (1);
	}

	printf("Stringa modificata: '%s'\n", mod);
	free(mod);

	return (0);
}*/
