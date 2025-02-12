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

char	**ft_split_add(char *str, char *add, char c);
char	*dupstr(char *str, int start);
int		confronta(char *s1, char *s2, int start, int end);
int		ft_slen(char *str);
int		check_output(char **av, int ac);
int		check_input(char **av);

#endif