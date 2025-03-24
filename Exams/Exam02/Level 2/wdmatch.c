/*Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
quarante deux$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$*/

#include <unistd.h>
#include <stdio.h>

#define TRUE
#define FALSE

void	ft_putstr(char *str)
{
	while (*str != 0)
	{
		write(1, str, 1);
		str++;
	}
}

int	check_doubles(char c, char *s, int j)
{
	int	i;

	i = j;
	while (s[i] != 0)
	{
		if (s[i] == c)
		{
			//write(1, &c, 1);
			//printf("%d", i);
			return 0;
		}
		i++;
	}
	return 1;
}

int	wdmatch(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != 0 && s2[j] != 0)
	{
		if (check_doubles(s1[i], s2, j) == 1)
		{
			//ft_putstr(s1);
			return 1;
		}
		j++;
		i++;
	}
	return 0;
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (wdmatch(argv[1], argv[2]) == 0)
			ft_putstr(argv[1]);
	}
	write(1, "\n", 1);
	return 0;
}