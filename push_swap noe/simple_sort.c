#include "push_swap.h"
// funzioni per il sorting con meno di 5 elementi
int	get_min(t_node **lista, int valore)
{
	t_node	*testa;
	int		min;

	min = -1;
	testa = *lista;
	min = testa->index;
	while (testa->next)
	{
		testa = testa->next;
		if ((testa->index < min) && testa->index != valore)
			min = testa->index;
	}
	return (min);
}

void	do_moves(t_node **lista, t_node *testa, int min, int next_min)
{
	if (testa->index == min && testa->next->index != next_min)
	{
		ra(lista);
		sa(lista);
		rra(lista);
	}
	else if (testa->index == next_min)
	{
		if (testa->next->index == min)
			sa(lista);
		else
			rra(lista);
	}
	else
	{
		if (testa->next->index == min)
			ra(lista);
		else
		{
			sa(lista);
			rra(lista);
		}
	}
}

void	sort_three(t_node **lista)
{
	int		min;
	int		next_min;
	t_node	*testa;

	min = get_min(lista, -1);
	next_min = get_min(lista, min);
	if (is_sorted(lista))
		return ;
	else
	{
		testa = *lista;
		do_moves(lista, testa, min, next_min);
	}
}

void	sort_four(t_node **lista_a, t_node **lista_b)
{
	int	dist;

	if (is_sorted(lista_a))
		return ;
	dist = get_dist(lista_a, get_min(lista_a, -1));
	if (dist == 1)
		ra(lista_a);
	else if (dist == 2)
	{
		ra(lista_a);
		ra(lista_a);
	}
	else if (dist == 3)
	{
		rra(lista_a);
	}
	if (is_sorted(lista_a))
		return ;
	pb(lista_a, lista_b);
	sort_three(lista_a);
	pa(lista_a, lista_b);
}

void	sort_five(t_node **lista_a, t_node **lista_b)
{
	int	dist;

	if (is_sorted(lista_a))
		return ;
	dist = get_dist(lista_a, get_min(lista_a, -1));
	if (dist == 1)
		ra(lista_a);
	else if (dist == 2)
	{
		ra(lista_a);
		ra(lista_a);
	}
	else if (dist == 3)
	{
		rra(lista_a);
		rra(lista_a);
	}
	else if (dist == 4)
		rra(lista_a);
	if (is_sorted(lista_a))
		return ;
	pb(lista_a, lista_b);
	sort_four(lista_a, lista_b);
	pa(lista_a, lista_b);
}
