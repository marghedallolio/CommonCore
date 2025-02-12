/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:34:47 by mdalloli          #+#    #+#             */
/*   Updated: 2024/11/22 10:34:53 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static void	ft_strconcat(char *dest, const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest [i + j] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strconcat(result, s1, s2);
	return (result);
}
/*
int	main(void)
{
	char *s1 = "ciao, ";
	char *s2 = "bla!";
	char *result;

	result = ft_strjoin(s1, s2);
	if (result)
	{
		printf("Stringa concatenata: %s\n", result);
		free(result);
	}
	else
	{
		printf("Errore nell'allocazione della memoria.\n");
	}
	return (0);
}*/
