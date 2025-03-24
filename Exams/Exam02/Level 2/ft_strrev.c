/*Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);*/

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int len;
	
	len = 0;
	while(str[len] != '\0')
		len++;
	return (len);
}
char    *ft_strrev(char *str)
{
    int i = 0;
    int len = ft_strlen(str);
    char temp;

    while (i < len) // Swap characters
    {
        temp = str[i];
        str[i] = str[len];
        str[len] = temp;
        i++;
        len--;
    }
    return (str);
}
/*
int main(void)
{
    char str[] = "Hello";
    printf("Reversed: %s\n", ft_strrev(str));
    return 0;
}*/
