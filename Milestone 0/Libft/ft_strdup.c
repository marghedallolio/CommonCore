/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:10:04 by mdalloli          #+#    #+#             */
/*   Updated: 2024/11/19 17:10:06 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		i;
	size_t		len;
	char		*dst;

	len = ft_strlen(s);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = s[i];
		i++;
	}
	dst[len] = '\0';
	return (dst);
}
/*
int	main(void)
{
	const char	*orig = "basta test";
	char	*dup;
	printf("stringa originale %s\n", orig);
	dup = ft_strdup(orig);
	if(dup)
	{
		printf("stringa duplicata: %s\n", dup);
		free(dup);
	}
	else
		printf("Errore nell'allocazione di memoria. \n");
	return (0);
}*/
