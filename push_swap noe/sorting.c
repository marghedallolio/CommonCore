#include "push_swap.h"

bool	is_sorted(t_node **lista)
{
	t_node	*testa;

	testa = *lista;
	while (testa && testa->next)
	{
		if (testa->value > testa->next->value)
			return (false);
		testa = testa->next;
	}
	return (true);
}

void	sorting_type(t_node **lista_a, t_node **lista_b)
{
	int	dim;

	dim = ft_lstsize(*lista_a);
	if (dim == 0)
		return ;
	if (dim <= 5)
		simple_sort(lista_a, lista_b);
	else
		radix_sort(lista_a, lista_b);
}

void	simple_sort(t_node **lista_a, t_node **lista_b)
{
	int	size;

	if (is_sorted(lista_a) || ft_lstsize(*lista_a) == 0
		|| ft_lstsize(*lista_a) == 1)
		return ;
	size = ft_lstsize(*lista_a);
	if (size == 2)
		sa(lista_a);
	else if (size == 3)
		sort_three(lista_a);
	else if (size == 4)
		sort_four(lista_a, lista_b);
	else if (size == 5)
		sort_five(lista_a, lista_b);
}
