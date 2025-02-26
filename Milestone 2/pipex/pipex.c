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
	free(arr);
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
	while (env[i] && compare_substring(env[i], "PATH=", 0, 5) == 0)
		i++;
	if (!env[i]) // Se PATH non esiste, esci subito
		return (NULL);
	path = dupstr(env[i], 5);
	com = ft_split_add(command, NULL, ' ');
	search = ft_split_add(path, com[0], ':');
	i = -1;
	while (search[++i] != NULL)
	{
		if (access(search[i], X_OK) == 0)
		{
			path = dupstr(search[i], 0);
			free_arr(com);
			free_arr(search);
			return (path);
		}
	}
	free_arr(com); // Libera anche se nessun percorso è valido
	free_arr(search);
	return (NULL);
}

/*esegue un comando utilizzando execeve
si occupa della gestione della memoria liberando gli array allocati*/
void	execute_command(char *command, char **env)
{
	char	**arg;
	char	*path;
	int		is_allocated;

	is_allocated = 1;
	path = create_path(command, env);
	if (!path)
	{
		path = command;
		is_allocated = 0;
	}
	arg = ft_split_add(command, NULL, ' ');
	if (execve(path, arg, env) == -1)
	{
		if (is_allocated)
			free(path); // Libera solo se allocato
		free_arr(arg);
		ft_putstr_fd("Error, no process\n", 2);
		exit(EXIT_FAILURE);
	}
	if (is_allocated)
		free(path);
	free_arr(arg);
}


void	fork_and_pipe(char *cmd1, char *cmd2, char **env, int fd_in, int fd_out)
{
	pid_t	pid;
	pid_t	pid2;
	int		pip[2];

	if (pipe(pip) == -1)
		exit(ft_printf("Pipe error"));
	pid = fork();
	if (pid == 0)
	{
		if (dup2(fd_in, STDIN_FILENO) == -1)
			exit(ft_printf("Error, bad dup\n"));
		if (dup2(pip[1], STDOUT_FILENO) == -1)
			exit(ft_printf("Error, bad dup\n"));
		close(fd_in); // Close fd_in as it's no longer needed
		close(pip[0]); // Close the reading end of the pipe
		close(pip[1]); // Close the writing end of the pipe after dup2
		execute_command(cmd1, env);
	}
	else
	{
		pid2 = fork();
		if (pid2 == 0)
		{
			if (dup2(fd_out, STDOUT_FILENO) == -1)
				exit(ft_printf("Error, bad dup\n"));
			if (dup2(pip[0], STDIN_FILENO) == -1) // Change to read from pipe
				exit(ft_printf("Error, bad dup\n"));
			close(fd_out); // Close fd_out as it's no longer needed
			close(pip[0]); // Close the reading end of the pipe after dup2
			close(pip[1]); // Close the writing end of the pipe
			execute_command(cmd2, env);
		}
		close(pip[0]); // Close the reading end in parent process
		close(pip[1]); // Close the writing end in parent process
		waitpid(pid, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
}

int	main(int ac, char **av, char **env)
{
	int		fd_out;
	int		fd_in;

	if (ac != 5)
		return (ft_printf("Error, too few arguments\n"), 127);
	fd_in = open(av[1], O_RDONLY); // Use O_RDONLY instead of O_RDWR for input
	if (fd_in < 0)
		return (ft_printf("Input file open error\n"), 127); // Check for error in opening input file
	fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777); // Ensure the output file has proper permissions
	if (fd_out < 0)
		return (ft_printf("Output file open error\n"), 127); // Check for error in opening output file
	fork_and_pipe(av[2], av[3], env, fd_in, fd_out);
	close(fd_in);
	close(fd_out);
}
