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
	while (compare_substring(env[i], "PATH=", 0, 5) == 0) // trova la variabile PATH in env
		i++;
	path = dupstr(env[i], 5);   // estrae i percorsi della variabile PATH
	com = ft_split_add(command, NULL, ' ');    // divide il comando in argomenti
	search = ft_split_add(path, com[0], ':');  // genera i percorsi possibili
	i = -1;
	while (search[++i] != NULL)
	{
		if (access(search[i], X_OK) == 0)   // controlla se il file e' eseguibile in X_OK
		{
			path = dupstr(search[i], 0);
			return (free_arr(com), free_arr(search), path);  // restituisce il percorso completo
		}
	}
	return (NULL);
}

/*esegue un comando utilizzando execeve
si occupa della gestione della memoria liberando gli array allocati*/
void	execute_command(char *command, char **env)
{
	char	**arg;
	char	*path;

	path = create_path(command, env);        // ottiene il percorso eseguibile
	arg = ft_split_add(command, NULL, ' ');  // divide il comando in argomenti
	// la funzione exceve sostituisce il processo figlio con un nuovo programma, eseguendolo con i parametri specificati
	if (execve(path, arg, env) == -1)   // se exceve fallisce stampa un errore, libera la memoria allocata ed esce
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
int	fork_and_pipe(char *cmd, char **env)
{
	pid_t	pid;
	int		pip[2];

	pipe(pip);     // crea una pipe
	pid = fork();  // genera un processo figlio (il padre e il figlio continuano ad eseguire il codice)
	if (pid == 0)  // caso figlio 
	{
		close(pip[0]);  // chiude pip[0] (non legge)
		if (dup2(pip[1], STDOUT_FILENO) == -1)   // reindirizza stdout alla pipe
			return (ft_printf("Error, bad dup\n"), 0);
		execute_command(cmd, env);   // esegue cmd
	}
	else
	{
		close(pip[1]);  //chiude pip[1] (non scrive)
		if (dup2(pip[0], STDIN_FILENO) == -1)  // reindirizza stdin alla pipe
			return (ft_printf("Error, bad dup\n"), 0);
	}
	return (1);
}

/*valida  gli argomenti e inizializza i descrittori di file
processa i comandi e gestisce la pipeline in un ciclo */
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
		if (fork_and_pipe(av[i], env) == 0)
			return (ft_printf("Error, bad input dup\n"), 127);
	if (dup2(fd_out, 1) == -1)
		return (ft_printf("Error, bad output dup\n"), 127);
	execute_command(av[i], env);
	return (0);
}
