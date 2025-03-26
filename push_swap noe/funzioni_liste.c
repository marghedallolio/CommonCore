#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*temp;

	temp = (t_node *)malloc(sizeof(t_node));
	if (!temp)
		return (NULL);
	temp->value = value;
	temp->index = -1;
	temp->next = NULL;
	return (temp);
}

void	ft_lstadd_back(t_node **stack, t_node *new)
{
	t_node	*n;

	if (*stack)
	{
		n = last_node(*stack);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

t_node	*last_node(t_node *lista)
{
	t_node	*coda;

	coda = lista;
	while (coda->next)
	{
		coda = coda->next;
		if (coda->next == NULL)
			return (coda);
	}
	return (coda);
}
