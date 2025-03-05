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
	if (!env[i])
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
			return (free_arr(com), free_arr(search), path);
		}
	}
	free_arr(com);
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
			free(path);
		free_arr(arg);
		ft_putstr_fd("Error, no process\n", 2);
		exit(EXIT_FAILURE);
	}
	if (is_allocated)
		free(path);
	free_arr(arg);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	if (ac != 5)
		return (ft_printf("Error, too few arguments\n"), 127);
	pipex.fd_in = open(av[1], O_RDONLY);
	if (pipex.fd_in < 0)
		return (ft_printf("Input file open error\n"), 127);
	pipex.fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex.fd_out < 0)
		return (ft_printf("Output file open error\n"), 127);
	pipex.cmd1 = av[2];
	pipex.cmd2 = av[3];
	fork_and_pipe(&pipex, env);
	close(pipex.fd_in);
	close(pipex.fd_out);
}
