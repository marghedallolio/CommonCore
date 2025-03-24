/* Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$> */

#include <unistd.h>

int	char_to_index(char c)
{
	int	i;
	
	i = 0;	
	if (c >= 65 && c <= 90)
                i = c - 64;
        if (c >= 97 && c <= 122)
                i = c - 96;
        return (i);
}

int	main(int argc, char **argv)
{
	unsigned int	i;
	unsigned int 	j;
	unsigned int	t;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i] != 0)
		{
			if ((argv[1][i] >= 65 && argv[1][i] <= 90)
				|| (argv[1][i] >= 97 && argv[1][i] <= 122))
			{
				t = char_to_index(argv[1][i]);
				j = 1;
				while (j <= t)
				{
					write(1, &argv[1][i], 1);
					j++;
				}
			}
			else
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}