/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:49:22 by mdalloli          #+#    #+#             */
/*   Updated: 2025/03/04 17:49:23 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_process1(t_pipex pipex, char **env)
{
	if (dup2(pipex.fd_in, STDIN_FILENO) == -1)
		exit(ft_printf("Error,1 bad dup\n"));
	if (dup2(pipex.pip[1], STDOUT_FILENO) == -1)
		exit(ft_printf("Error,2 bad dup\n"));
	close_all(pipex);
	execute_command(pipex.cmd1, env);
}

static void	child_process2(t_pipex pipex, char **env)
{
	if (dup2(pipex.fd_out, STDOUT_FILENO) == -1)
		exit(ft_printf("Error,3 bad dup\n"));
	if (dup2(pipex.pip[0], STDIN_FILENO) == -1)
		exit(ft_printf("Error,4 bad dup\n"));
	close_all(pipex);
	execute_command(pipex.cmd2, env);
}

void	fork_and_pipe(t_pipex *pipex, char **env)
{
	pid_t	pid;
	pid_t	pid2;

	if (pipe(pipex->pip) == -1)
	{
		perror("Pipe error");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == 0)
		child_process1(*pipex, env);
	else
	{
		pid2 = fork();
		if (pid2 == 0)
			child_process2(*pipex, env);
		close(pipex->pip[0]);
		close(pipex->pip[1]);
		waitpid(pid, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
}
