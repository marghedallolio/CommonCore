#include "push_swap.h"

bool	reverse_rotate(t_node **lista)
{
	t_node	*testa;
	t_node	*coda;

	if (ft_lstsize(*lista) < 2)
		return (false);
	testa = *lista;
	coda = last_node(testa);
	while (testa)
	{
		if (testa->next && testa->next->next == NULL)
		{
			testa->next = NULL;
			break ;
		}
		testa = testa->next;
	}
	coda->next = *lista;
	*lista = coda;
	return (true);
}

bool	rra(t_node **listaA)
{
	if (reverse_rotate(listaA) == false)
		return (false);
	ft_printf("rra");
	return (true);
}

bool	rrb(t_node **listaB)
{
	if (reverse_rotate(listaB) == false)
		return (false);
	ft_printf("rrb");
	return (true);
}

bool	rrr(t_node **listaA, t_node **listaB)
{
	if ((ft_lstsize(*listaA) < 2) || (ft_lstsize(*listaB) < 2))
		return (false);
	rra(listaA);
	rrb(listaB);
	ft_printf("rrr");
	return (true);
}
