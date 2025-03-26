/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npezzati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:37:43 by npezzati          #+#    #+#             */
/*   Updated: 2024/11/25 17:37:52 by npezzati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all(char **arr, size_t i)
{
	while (i > 0)
		free(arr[--i]);
	free(arr);
}

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	**craft(char const *s, char **result, char c, size_t word_count)
{
	size_t	i;
	size_t	end;
	size_t	start;

	start = 0;
	i = 0;
	while (i < word_count)
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		result[i] = ft_substr(s, start, end - start);
		if (!result[i])
		{
			free_all(result, i);
			return (NULL);
		}
		start = end;
		i++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	return (craft(s, result, c, word_count));
}
/*int	main(void)
{
	const char *str1 = "Ciao come va?";
	char **result1 = ft_split(str1, ' ');
	printf("Test 1: Separazione con spazio\n");
	if (result1)
	{
		for (int i = 0; result1[i] != NULL; i++)
			printf("Risultato %d: '%s'\n", i + 1, result1[i]);
		for (int i = 0; result1[i] != NULL; i++)
			free(result1[i]);
		free(result1);
	}
	else
		printf("Errore nella separazione.\n");
	return (0);
}*/
