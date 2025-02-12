/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:58:47 by mdalloli          #+#    #+#             */
/*   Updated: 2025/01/21 14:58:50 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*libera la  memoria allocata per un array di stringhe */
void	free_arr(char **arr)
{
	int		j;

	j = -1;
	while (arr[++j])
		free(arr[j]);
}

/*cerca il percorso completo di un comando analizzando la variabile d'ambiente 
PATH, divide il contenuto di path in directory, aggiunge il comando e 
controlla se ogni percorso e' eseguibile (access con X_OK)*/
char	*create_path(char *command, char **env)
{
	int		i;
	char	*path;
	char	**search;
	char	**com;

	i = 0;
	while (confronta(env[i], "PATH=", 0, 5) == 0)
		i++;
	path = dupstr(env[i], 5);
	com = ft_split_add(command, NULL, ' ');
	search = ft_split_add(path, com[0], ':');
	i = -1;
	while (search[++i] != NULL)
	{
		if (access(search[i], X_OK) == 0)
		{
			path = dupstr(search[i], 0);
			return (free_arr(com), free_arr(search), path);
		}
	}
	return (NULL);
}

/*esegue un comando utilizzando execeve
si occupa della gestione della memoria liberando gli array allocati*/
void	process(char *command, char **env)
{
	char	**arg;
	char	*path;

	path = create_path(command, env);
	arg = ft_split_add(command, NULL, ' ');
	if (execve(path, arg, env) == -1)
	{
		free(path);
		free_arr(arg);
		ft_putstr_fd("Error, no process", 2);
		exit (EXIT_FAILURE);
	}
	free(path);
	free_arr(arg);
}

/*crea una pipe, genera un processo figlio (fork) e gestisce la redirezione di 
input/output utilizzando dup2*/
int	cicle(char *cmd, char **env)
{
	pid_t	pid;
	int		pip[2];

	pipe(pip);
	pid = fork();
	if (pid == 0)
	{
		close(pip[0]);
		if (dup2(pip[1], STDOUT_FILENO) == -1)
			return (ft_printf("Error, bad dup\n"), 0);
		process(cmd, env);
	}
	else
	{
		close(pip[1]);
		if (dup2(pip[0], STDIN_FILENO) == -1)
			return (ft_printf("Error, bad dup\n"), 0);
	}
	return (1);
}

/*valida  gli argomenti e inizializza i descrittori di file
processa i comandi e gestisce la pipeline in un ciclo 
include una gestione speciale per il comando here_doc*/
int	main(int ac, char **av, char **env)
{
	int		i;
	int		fd_out;
	int		fd_in;

	if (ac <= 4)
		return (ft_printf("Error, too few argoments\n"), 127);
	fd_in = check_input(av);
	fd_out = check_output(av, ac);
	if (fd_in == -1 || fd_out == -1)
		return (ft_printf("Error, file not opened\n"), 127);
	i = 1;
	while (++i < ac - 2)
		if (cicle(av[i], env) == 0)
			return (ft_printf("Error, bad input dup\n"), 127);
	if (dup2(fd_out, 1) == -1)
		return (ft_printf("Error, bad output dup\n"), 127);
	process(av[i], env);
	return (0);
}
