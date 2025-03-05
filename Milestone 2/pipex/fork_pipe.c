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

static void	child_process1(t_pipex pipex)
{
	if (dup2(pipex.fd_in, STDIN_FILENO) == -1)
	{
		perror("dup2 failed");
		exit(1);
	}
	if (dup2(pipex.pip[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 failed");
		exit(1);
	}
	close_all(pipex);
	execute_command(pipex.cmd1, pipex.env);
}

static void	child_process2(t_pipex pipex)
{
	if (dup2(pipex.fd_out, STDOUT_FILENO) == -1)
	{
		perror("dup2 failed");
		exit(1);
	}
	if (dup2(pipex.pip[0], STDIN_FILENO) == -1)
	{
		perror("dup2 failed");
		exit(1);
	}
	close_all(pipex);
	execute_command(pipex.cmd2, pipex.env);
}

void	fork_and_pipe(t_pipex pipex)
{
	pid_t	pid;
	pid_t	pid2;

	if (pipe(pipex.pip) == -1)
	{
		perror("Pipe error");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == 0)
		child_process1(pipex);
	else
	{
		pid2 = fork();
		if (pid2 == 0)
			child_process2(pipex);
		close(pipex.pip[0]);
		close(pipex.pip[1]);
		waitpid(pid, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
}
