/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:00:49 by mdalloli          #+#    #+#             */
/*   Updated: 2025/02/24 14:00:50 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**str;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		str = ft_split(argv[1], ' ');
	else
		str = &argv[1];
	init_stack(&a, str, argc);
	if (!stack_sorted(a))
	{
		if (stack_lenght(a) == 2)
			sa(&a, false);
		else if (stack_lenght(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	if (argc == 2)
		free_arr(str);
	free_stack(&a);
}
