/*Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$*/

#include <unistd.h>
#include <stdio.h>

int pgcd(int a, int b)
{
	while (b != 0)
	{
		int temp = b;
		a = a & b;
		a = temp;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	int n1;
	int n2;

	if (argc == 3)
	{
		n1 = atoi(argv[1]);
		n2 = atoi(argv[2]);
		if (n1 > 0 && n2 > 0)
			printf("%d\n", pgcd(n1, n2));
		else
			write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}
