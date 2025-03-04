/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:03:11 by mdalloli          #+#    #+#             */
/*   Updated: 2025/01/23 15:03:15 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_all(t_pipex pipex)
{
	close(pipex.fd_in);
	close(pipex.fd_in);
	close(pipex.pip[0]);
	close(pipex.pip[1]);
}

/*duplica una stringa a partire da start*/
char	*dupstr(char *str, int start)
{
	char	*app;
	int		i;

	if (start >= ft_strlen(str))
		return (NULL);
	app = malloc(ft_strlen(str) + 1 - start);
	i = -1;
	while (str[start])
		app[++i] = str[start++];
	app[++i] = '\0';
	return (app);
}

/*confronta due stringhe in base a un intervallo (start fino a end)
1 se le stringhe coincidono nell'intervallo 
0 in caso contrario 
-1 per intervalli non validi*/
int	compare_substring(char *s1, char *s2, int start, int end)
{
	int	i;

	if (end != -1 && (start < 0 || start >= end
			|| end > ft_strlen(s1) || end > ft_strlen(s2)))
		return (-1);
	i = start - 1;
	if (end == -1)
	{
		if (ft_strlen(s1) != ft_strlen(s2))
			return (0);
		while (s1[++i])
		{
			if (s1[i] != s2[i])
				return (0);
		}
	}
	else
	{
		while (++i < end)
		{
			if (s1[i] != s2[i])
				return (0);
		}
	}
	return (1);
}

/*gestisce l'input in base ai parametri della riga di comando (av)
apre il file di input e redirige l'input standard sul file 
restituisce il file descriptor per il file di input*/
int	check_input(char **av)
{
	int	fd_in;

	fd_in = open(av[1], O_RDWR);
	if (dup2(fd_in, 0) == -1)
		return (ft_printf("Error, bad input dup\n"), 0);
	close(fd_in);
	return (fd_in);
}

/* gestisce l'output in base ai parametri della riga di comando (av, ac)
apre il file di output in mod truncate 
restituisce il file descriptor per il file di output*/
int	check_output(char **av, int ac)
{
	int	fd_out;

	fd_out = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd_out == -1)
		return (ft_printf("Error, failed to open input file\n"), -1);
	close(fd_out);
	return (fd_out);
}
