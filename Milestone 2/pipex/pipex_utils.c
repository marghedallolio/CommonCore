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

/*duplica una stringa a partire da start*/
char	*dupstr(char *str, int start)
{
	char	*app;
	int		i;

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
int	confronta(char *s1, char *s2, int start, int end)
{
	int	i;

	if (start < 0 || (start >= end && end != -1))
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
se il primo argomento e' here_doc, attiva una modalita' di input interattiva
in caso contrario apre il file di input e redirige l'input standard sul file 
restituisce il file descriptor per il file di input o 
0 per il caso di here_doc*/
int	check_input(char **av)
{
	int		fd_in;
	int		pip[2];
	char	*buf;

	if (confronta(av[1], "here_doc", 0, -1))
	{
		pipe(pip);
		ft_printf("pipe heredoc> ");
		buf = get_next_line(0);
		while (confronta(buf, av[2], 0, ft_strlen(av[2])) == 0)
		{
			write(pip[1], buf, ft_strlen(buf));
			ft_printf("pipe heredoc> ");
			buf = get_next_line(0);
		}
		close(pip[1]);
		if (dup2(pip[0], 0) == -1)
			return (ft_printf("Error\nbad input dup\n"), 0);
		return (0);
	}
	fd_in = open(av[1], O_RDWR);
	if (dup2(fd_in, 0) == -1)
		return (ft_printf("Error\nbad input dup\n"), 0);
	return (fd_in);
}

/* gestisce l'output in base ai parametri della riga di comando (av, ac)
se il primo argomento e' here_doc apre il file di output in append
altrimenti apre il file di output in mod truncate 
restituisce il file descriptor per il file di output*/
int	check_output(char **av, int ac)
{
	int		fd_out;

	if (confronta(av[1], "here_doc", 0, -1))
	{
		fd_out = open(av[ac - 1], O_RDWR | O_CREAT | O_APPEND, 0777);
		return (fd_out);
	}
	fd_out = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	return (fd_out);
}
