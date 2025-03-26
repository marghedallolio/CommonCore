#include "push_swap.h"

bool	push(t_node **lista1, t_node **lista2)
{
	t_node	*tmp;
	t_node	*testa_a;
	t_node	*testa_da;

	if (ft_lstsize(*lista2) == 0)
		return (false);
	testa_a = *lista1;
	testa_da = *lista2;
	tmp = testa_da;
	testa_da = testa_da->next;
	*lista2 = testa_da;
	if (!testa_a)
	{
		testa_a = tmp;
		testa_a->next = NULL;
		*lista1 = testa_a;
	}
	else
	{
		tmp->next = testa_a;
		*lista1 = tmp;
	}
	return (true);
}

bool	pa(t_node **listaA, t_node **listaB)
{
	if (push(listaA, listaB) == false)
		return (false);
	ft_printf("pa\n");
	return (true);
}

bool	pb(t_node **listaA, t_node **listaB)
{
	if (push(listaB, listaA) == false)
		return (false);
	ft_printf("pb\n");
	return (true);
}
