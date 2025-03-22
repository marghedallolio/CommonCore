/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:28:42 by mdalloli          #+#    #+#             */
/*   Updated: 2025/03/18 16:28:50 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*verifica se una stringa rappresenta un numero intero valido*/
int	error_syntax(char *str)
{
	int	i;

	if (!str || !*str)
		return (1);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

/*verifica se un numero n è già presente nella lista*/
int	error_dup(t_stack_node *a, int n)
{
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

/*libera la memoria della stack a, stampa un messaggio di errore 
e termina il programma*/
void	free_error(t_stack_node **a)
{
	free_stack(a);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

/*libera lo stack*/
void	free_stack(t_stack_node **a)
{
	t_stack_node	*temp;

	while (*a)
	{
		temp = *a;
		*a = (*a)->next;
		free(temp);
	}
	*a = NULL;
}

/*libera l'array*/
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
