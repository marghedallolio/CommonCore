/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:46:59 by mdalloli          #+#    #+#             */
/*   Updated: 2024/11/18 14:47:01 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	char	*s1 = "ciao";
	char	*s2 = "42";
	char	*s3 = "stringa lunga";
	printf("Stringa: \"%s\" -> Lunghezza: %zu\n", s1, ft_strlen(s1));
	printf("Stringa: \"%s\" -> Lunghezza: %zu\n", s2, ft_strlen(s2));
	printf("Stringa: \"%s\" -> Lunghezza: %zu\n", s3, ft_strlen(s3));
	return (0);
}*/
