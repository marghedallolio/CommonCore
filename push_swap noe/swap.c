#include "push_swap.h"

bool	swap(t_node **lista)
{
	t_node	*testa;
	t_node	*next;
	int		tmp_val;
	int		tmp_index;

	if (ft_lstsize(*lista) < 2)
		return (false);
	testa = *lista;
	next = testa->next;
	if (!testa && !next)
		free_list(lista);
	tmp_val = testa->value;
	tmp_index = testa->index;
	testa->value = next->value;
	testa->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (true);
}

bool	sa(t_node **listaA)
{
	if (swap(listaA) == false)
		return (false);
	ft_printf("sa\n");
	return (true);
}

bool	sb(t_node **listaB)
{
	if (swap(listaB) == false)
		return (false);
	ft_printf("sb\n");
	return (true);
}

bool	ss(t_node **listaA, t_node **listaB)
{
	if ((ft_lstsize(*listaA) < 2) || (ft_lstsize(*listaA) < 2))
		return (false);
	sb(listaB);
	sa(listaA);
	ft_printf("ss\n");
	return (true);
}
