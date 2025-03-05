/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:58:59 by mdalloli          #+#    #+#             */
/*   Updated: 2025/01/21 14:59:01 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft_printf/libft_printf.h"

typedef struct s_pipex_args
{
	char	*cmd1;
	char	*cmd2;
	char	**env;
	int		fd_in;
	int		fd_out;
	int		pip[2];
}	t_pipex;

char	**ft_split_add(char *str, char *add, char c);
char	*dupstr(char *str, int start);
char	*create_path(char *command, char **env);
char	**get_search_paths(char *command, char **env);
int		compare_substring(char *s1, char *s2, int start, int end);
int		ft_strlen(const char *s);
void	fork_and_pipe(t_pipex pipex);
void	close_all(t_pipex pipex);
void	free_arr(char **arr);
void	execute_command(char *command, char **env);

#endif