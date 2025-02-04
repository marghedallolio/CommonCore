/* Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b); */

#include <unistd.h>
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int app;

	app = *b;
	*b = *a;
	*a = app;
}
/* 
int	main(void)
{
	int a = 7;
	int b = 17;
	printf("a iniziale %d\n", a);
	printf("b iniziale %d\n", b);
	ft_swap(&a, &b);
	printf("a dopo swap %d\n", a);
	printf("b dopo swap %d\n", b);
	return (0);
} */