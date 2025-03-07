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
	com = ft_split(command, ' ');
	search = ft_split_add(path, com[0], ':', 1);
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
void	execute_command(char *command, char **env, t_pipex pipex)
{
	char	**arg;
	char	*path;

	arg = ft_split(command, ' ');
	if (!arg)
		exit(EXIT_FAILURE);
	path = create_path(command, env);
	if (!path)
		path = command;
	if (access(path, X_OK) != 0)
	{
		ft_putstr_fd("Error, command not found\n", 2);
		free_arr(arg);
		if (path != command)
			free(path);
		close_dp();
		close_all(pipex);
		exit(EXIT_FAILURE);
	}
	if (execve(path, arg, env) == -1)
	{
		failed_execeve(pipex, path, arg);
		exit(127);
	}
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	if (ac != 5)
		return (ft_printf("Error, 4 arguments required\n"), 127);
	pipex.fd_in = open(av[1], O_RDONLY);
	if (pipex.fd_in < 0)
		return (ft_printf("Input file open error\n"), 127);
	pipex.fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex.fd_out < 0)
	{
		close(pipex.fd_in);
		return (ft_printf("Outfile file open error\n"), 127);
	}
	pipex.cmd1 = av[2];
	pipex.cmd2 = av[3];
	fork_and_pipe(&pipex, env);
	close(pipex.fd_in);
	close(pipex.fd_out);
	return (0);
}
