/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npezzati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:38:08 by npezzati          #+#    #+#             */
/*   Updated: 2024/11/25 17:38:15 by npezzati         ###   ########.fr       */
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
	if (!(dst))
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
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
