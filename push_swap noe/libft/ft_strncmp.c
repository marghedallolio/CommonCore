/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npezzati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:52:19 by npezzati          #+#    #+#             */
/*   Updated: 2024/11/25 17:52:27 by npezzati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	const char *str1 = "ciao, come stai?";
	const char *str2 = "ciao, come va?";
	size_t n;

	n = 17;
	printf("Confronto dei primi %zu caratteri:\n", n);
	printf("Stringa 1: '%s'\n", str1);
	printf("Stringa 2: '%s'\n", str2);
	int result = ft_strncmp(str1, str2, n);
	if (result < 0)
		printf("Risultato: Stringa 1 è minore di Stringa 2.\n");
	else if (result > 0)
		printf("Risultato: Stringa 1 è maggiore di Stringa 2.\n");
	else
		printf("Risultato: Stringa 1 è uguale a Stringa 2.\n");
	return (0);
}*/
