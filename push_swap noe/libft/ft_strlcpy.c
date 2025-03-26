/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npezzati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:51:43 by npezzati          #+#    #+#             */
/*   Updated: 2024/11/25 17:51:50 by npezzati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
/*
int	main(void)
{
	char	src[] = "Ninonino";
	char	dest[21];
	char	sdest[7];
	
	size_t len1 = ft_strlcpy(dest, src, sizeof(dest));
	printf("Originale: %s\n", src);
	printf("Destinazione (grande): %s\n, Lunghezza buff: %zu\n", dest, len1);
	
	size_t len2 = ft_strlcpy(sdest, src, sizeof(sdest));
	printf("Destinazione (piccolo): %s\n, Lunghezza buff: %zu\n", sdest, len2);
	
	size_t len2 = ft_strlcpy(dest, src, 0);
	printf("Destinazione (piccolo): %s\n, Lunghezza buff: %zu\n", len3);
	
	return (0);
}*/
