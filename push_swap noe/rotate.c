#include "push_swap.h"

bool	rotate(t_node **lista)
{
	t_node	*testa;
	t_node	*coda;

	if (ft_lstsize(*lista) < 2)
		return (false);
	testa = *lista;
	coda = last_node(testa);
	*lista = testa->next;
	testa->next = NULL;
	coda->next = testa;
	return (true);
}

bool	ra(t_node **lista)
{
	if (rotate(lista) == false)
		return (false);
	ft_printf("ra\n");
	return (true);
}

bool	rb(t_node **lista)
{
	if (rotate(lista) == false)
		return (false);
	ft_printf("rb\n");
	return (true);
}

bool	rr(t_node **listaA, t_node **listaB)
{
	if ((ft_lstsize(*listaA) < 2) || (ft_lstsize(*listaB) < 2))
		return (false);
	rotate(listaA);
	rotate(listaA);
	ft_printf("rr\n");
	return (true);
}
