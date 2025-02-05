/*Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);*/

#include <unistd.h>

int	ft_strlen(char *str)
{
	int len;
	
	len = 0;
	while(str[len] != '\0')
		len++;
	return (len)
}

char	*ft_strrev(char *str)
{
	int i;
	int len;
	char tmp;

	i = 0;
	len = ft_strlen(str) - 1;
	while (len > i)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	return (str);
}