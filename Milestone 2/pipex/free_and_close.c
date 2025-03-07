/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:14:25 by mdalloli          #+#    #+#             */
/*   Updated: 2025/03/07 13:14:27 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*libera la  memoria allocata per un array di stringhe */
void	free_arr(char **arr)
{
	int		j;

	if (!arr)
		return ;
	j = -1;
	while (arr[++j])
		free(arr[j]);
	free(arr);
}

/*libera e chiude*/
void	close_dp(void)
{
	close(0);
	close(1);
}

/*chiude tutto*/
void	close_all(t_pipex pipex)
{
	close(pipex.fd_in);
	close(pipex.fd_out);
	close(pipex.pip[0]);
	close(pipex.pip[1]);
}

void	failed_execeve(t_pipex pipex, char *path, char **arg)
{
	ft_putstr_fd("Error, no process\n", 2);
	free_arr(arg);
	free(path);
	close_dp();
	close_all(pipex);
}
