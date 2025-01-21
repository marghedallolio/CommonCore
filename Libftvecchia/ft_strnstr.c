/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:50:08 by mdalloli          #+#    #+#             */
/*   Updated: 2024/11/19 17:50:11 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (i + j < len && big[i + j] != '\0' && big[i + j] == little[j])
			{
				j++;
				if (little[j] == '\0')
					return ((char *)(big + i));
			}
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char *big1 = "Ciao, come va?";
	const char *little1 = "come";
	size_t len1 = 15;

	char *result1 = ft_strnstr(big1, little1, len1);

	if (result1)
		printf("Test 1: Sottostringa trovata: '%s'\n", result1);
	else
		printf("Test 1: Sottostringa non trovata.\n");
	return (0);
}*/
