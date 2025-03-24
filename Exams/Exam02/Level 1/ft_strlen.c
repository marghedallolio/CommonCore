/* Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the length of a string.

Your function must be declared as follows:

int	ft_strlen(char *str); */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while(str[len] != '\0')
		len++;
	return(len);
}
/* int	main(void)
{
	int len;

	len = ft_strlen("ciao");
	printf("%d\n", len);
	return (0);
} */
