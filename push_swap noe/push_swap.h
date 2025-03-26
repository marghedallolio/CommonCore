#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

/* typedef struct s_nodo
{
	int value;
	int index;
	struct s_nodo *next;
}	t_node; */

//free.c
void		ft_error(char **str, int ac);
void		free_list(t_node **lista);
void		ft_free(char **str);

//funzioni_liste.c
int			ft_lstsize(t_node *lista);
t_node		*create_node(int value);
void		ft_lstadd_back(t_node **stack, t_node *new);
t_node		*last_node(t_node *lista);

//index.c
t_node		*get_min_node(t_node **lista);
void		node_index(t_node **lista);

//init.c
void		init_list(t_node **lista, int ac, char **av);

//radix_sort.c
int			get_max_bits(t_node **lista);
void		radix_sort(t_node **listaA, t_node **listaB);

//simple_sort.c
int			get_min(t_node **lista, int valore);
void		simple_sort(t_node **lista_a, t_node **lista_b);
void		do_moves(t_node **lista, t_node *testa, int min, int next_min);
void		sort_five(t_node **lista_a, t_node **lista_b);
void		sort_four(t_node **lista_a, t_node **lista_b);
void		sort_three(t_node **lista);

//sorting.c
void		sorting_type(t_node **lista_a, t_node **lista_b);
bool		is_sorted(t_node **lista_a);

//push.c
bool		push(t_node **a, t_node **b);
bool		pa(t_node **listaA, t_node **listaB);
bool		pb(t_node **listaA, t_node **listaB);

//reverse_rotate.c
bool		reverse_rotate(t_node **lista);
bool		rra(t_node **listaA);
bool		rrb(t_node **listaB);
bool		rrr(t_node **listaA, t_node **listaB);

//rotate.c
bool		rotate(t_node **lista);
bool		ra(t_node **listaA);
bool		rb(t_node **listaB);
bool		rr(t_node **listaA, t_node **listaB);

//swap.c
bool		swap(t_node **listaA);
bool		ss(t_node **listaA, t_node **listaB);
bool		sa(t_node **listaA);
bool		sb(t_node **listaB);

//utils.c
int			sono_uguali(long nb, char **arg, int i);
bool		is_num(char *num);
void		check_arg(int ac, char **av);
int			get_dist(t_node **lista, int i);
long int	ft_atol(const char *s);

#endif