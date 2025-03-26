#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	**stack_a;
	t_node	**stack_b;

	if (argc < 2)
		return (-1);
	check_arg(argc, argv);
	stack_a = (t_node **)malloc(sizeof(t_node *));
	stack_b = (t_node **)malloc(sizeof(t_node *));
	*stack_a = NULL;
	*stack_b = NULL;
	init_list(stack_a, argc, argv);
	if (!is_sorted(stack_a))
		sorting_type(stack_a, stack_b);
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}
