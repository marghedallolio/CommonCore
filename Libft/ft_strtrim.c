/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:35:18 by mdalloli          #+#    #+#             */
/*   Updated: 2024/11/22 12:35:19 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	while(*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	trimmed = (char *)malloc(len + 1);
	if (!trimmed)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if(!ft_isset(s1[i], set))
		{
			trimmed[j] = s1[i];
			j++;
		}
		i++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}

int main(void)
{
	char	*s1 = "  ciaoooo blabla  ";
	char	*set = " ";
	char	*result = ft_strtrim(s1, set);

	if (result)
	{
		printf("Stringa originale: %s\n", s1);
		printf("Trimmed string: %s\n", result);
		free(result);
	}
	else
		printf("Error: Memory allocation failed.\n");
	return 0;
}
