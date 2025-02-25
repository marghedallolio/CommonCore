/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:39:11 by mdalloli          #+#    #+#             */
/*   Updated: 2025/01/25 11:39:12 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*se which == 0 conta il numero di parole (sottostringhe separate da c)
se which == 1 restituisce la lunghezza della parola che inizia da where*/
int	count(char *str, int which, int where, char c)
{
	int	i;
	int	line;

	if (which == 0)
	{
		i = -1;
		line = 1;
		while (str[++i])
			if (i != 0 && str[i] == c && str[i - 1] != c)
				line++;
		return (line);
	}
	i = 0;
	while (str[i + where] || str[i + where] == '\n')
		i++;
	return (i);
}
/*divide str in parole e le memorizza nell'array arr*/
void	copy(char *str, char **arr, char c)
{
	int	i;
	int	j;
	int	y;

	i = -1;
	j = -1;
	y = 0;
	arr[y] = malloc(count(str, 1, 0, c) + 1);
	while (str[++i])
	{
		if (str[i] != c)
			arr[y][++j] = str[i];
		else if (i != 0 && str[i] == c && str[i - 1] != c) // quando trova c, chiude la parola corrente ('\0') e ne alloca una nuova
		{
			arr[y][++j] = '\0';
			arr[++y] = malloc(count(str, 1, i + 1, c) + 1);
			j = -1;
		}
	}
	arr[y][++j] = '\0';
	arr[++y] = NULL;
}
/*concatena s1 e s2 separandoli con '/'*/
char	*ft_strjoin2(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = count(s1, 1, 0, ' ');  // lunghezza s1
	len_s2 = count(s2, 1, 0, ' ');  // lunghezza s2
	str = malloc(len_s1 + len_s2 + 2);
	if (!str)
		return (NULL);
	str[len_s1 + len_s2 + 1] = '\0'; // carettere finale 
	str[len_s1] = '/'; // aggiunge separatore tra s1 e s2
	while (--len_s2 >= 0)
		str[len_s1 + len_s2 + 1] = s2[len_s2];
	while (--len_s1 >= 0)
		str[len_s1] = s1[len_s1];
	return (str);
}

/*divide str in parole e aggiunge add a ciascuna di esse*/
char	**ft_split_add(char *str, char *add, char c)
{
	char	**arr;
	char	*temp;
	int		i;

	if (str == NULL)
		return (NULL);
	if (c == '\0')
		return (NULL);
	i = count(str, 0, 0, c);
	arr = malloc((i + 1) * sizeof(char *));
	copy(str, arr, c); // riempie arr con le parole
	while (--i >= 0 && add != NULL)
	{
		temp = ft_strjoin2(arr[i], add); // concatena add a ogni parola
		free(arr[i]);
		arr[i] = temp;
	}
	return (arr);
}
