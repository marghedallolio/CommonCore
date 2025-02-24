/*Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>*/

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	char c = (n % 10) + '0';
	write(1, &c, 1);
}

int     is_prime(int n)
{
	int i;
	if (n < 2)
		return 0;
	i = 2;
	while (i * i <= n)
	{
		if (n % i == 0)
			return 0;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	n;
	int	sum;
	int i;

	i = 2;
	if (argc == 2)
	{
		n = ft_atoi(argv[1]);
		if (n <= 0)
		{
			ft_putchar('\n');
			return (0);
		}
		sum = 0;
		while (i <= n)
		{
			if(is_prime(i))
				sum += i;
			i++;
		}
		ft_putnbr(sum);
	}
	ft_putchar('\n');
	return (0);
}
