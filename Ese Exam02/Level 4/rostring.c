/*Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>*/

#include <unistd.h>
#include <stdlib.h>

void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

// Funzione per saltare spazi e tab
char *skip_whitespace(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return str;
}

int main(int argc, char **argv)
{
	if (argc < 2)	
	{
		write(1, "\n", 1);
		return 0;
	}

	char *str = argv[1];
	char *start, *end;
	int first_word_len;

	// Saltare spazi iniziali
	str = skip_whitespace(str);
	start = str;

	// Trovare la fine della prima parola
	while (*str && *str != ' ' && *str != '\t')
		str++;
	end = str;
	first_word_len = end - start;

	// Stampare il resto delle parole
	while (*str) {
		str = skip_whitespace(str);
		if (*str)
		{
			while (*str && *str != ' ' && *str != '\t') 
			{
				write(1, str, 1);
				str++;
			}
			write(1, " ", 1);
		}
	}

	// Stampare la prima parola
	write(1, start, first_word_len);
	write(1, "\n", 1);

	return (0);
}

