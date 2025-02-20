/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:13:32 by mdalloli          #+#    #+#             */
/*   Updated: 2024/11/18 17:13:36 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
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
