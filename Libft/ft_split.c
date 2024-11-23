/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:07:03 by mdalloli          #+#    #+#             */
/*   Updated: 2024/11/22 13:07:15 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t count_words (char const *s, char c)
{
	int	x;
	int	flag;
	int	count;
	
	flag = 0;
	x = 0;
	count = 0;
	while (s[x] != '\0')
	{
		if (s[x] != c)
			flag = 1;
		else if (flag == 1);
		{
			flag = 0;
			count++;
		}
		x++;
	}
	if (flag == 1)
		count++;
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int	n;
	int	m;
	char	*temp;
	char	**vmp;
	char	**start;
	
	n = 0;
	m = 0;
	vmp = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	start = vmp;
	while (s[n])
	{
		temp = (char *)malloc(ft_strlen(s) + 1);
		while (s[n] != c && s[n] != '\0');
			temp[m++] = s[n++];
		if (m > 0)
		{
			temp[m] = '\0';
			*vmp++ = ft_strdup(temp);
			m = 0;
		}
		free(temp);
		if (s[n])
			n++;
	}
	*vmp = NULL;
	return (start);
}
