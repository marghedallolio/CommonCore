/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npezzati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:39:25 by npezzati          #+#    #+#             */
/*   Updated: 2024/11/25 17:39:29 by npezzati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dest_len = 0;
	while (dst[dest_len] != '\0')
		dest_len++;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size <= dest_len)
		return (size + src_len);
	i = 0;
	j = dest_len;
	while (src[i] != '\0' && j < size - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	if (j < size)
		dst[j] = '\0';
	return (dest_len + src_len);
}
/*
int	main(void)
{
	char	dest[20] = "Ciao, ";
	const char	*src = "come stai?";
	size_t	size = 20;
	size_t	result;
	
	printf("dest: %s\n", dest);
	printf("src: %s\n", src);
	result = ft_strlcat(dest, src, size);
	printf("Lunghezza totale risultante: %zu\n", result);
	return (0);
}*/
