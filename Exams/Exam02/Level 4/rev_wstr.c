/*Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.

If the number of parameters is different from 1, the program will display
'\n'.

In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>
*/

#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        char *str = argv[1];
        int i = 0;
        int j = 0;
        int k = 0;
        char **tab;
        tab = malloc(sizeof(char *) * 1000);
        while (str[i])
        {
            while (str[i] == ' ' || str[i] == '\t')
                i++;
            if (str[i])
            {
                tab[j] = malloc(ft_strlen(str) + 1);
                k = 0;
                while (str[i] && str[i] != ' ' && str[i] != '\t')
                {
                    tab[j][k] = str[i];
                    i++;
                    k++;
                }
                tab[j][k] = '\0';
                j++;
            }
        }
        while (--j >= 0)
        {
            write(1, tab[j], ft_strlen(tab[j]));
            if (j > 0)
                write(1, " ", 1);
            free(tab[j]);
        }
        free(tab);
    }
    write(1, "\n", 1);
    return (0);
}