#include "push_swap.h"

t_node	*get_min_node(t_node **lista)
{
	t_node	*head;
	t_node	*min;

	head = *lista;
	min = NULL;
	while (head)
	{
		if (head->index == -1 && (!min || head->value < min->value))
			min = head;
		head = head->next;
	}
	return (min);
}

// Assegna gli indici ai nodi in ordine crescente di valore
void	node_index(t_node **lista)
{
	t_node	*min;
	int		index;

	index = 0;
	min = get_min_node(lista);
	while (min != NULL)
	{
		min->index = index++;
		min = get_min_node(lista);
	}
}
