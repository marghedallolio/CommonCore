/*Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);*/

#include <unistd.h>

static int	ft_len(long nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
	{
		i++;
		if (nb == 0)
			return (i);
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static char	*build_itoa_str(long num, int len)
{
	char	*str;
	int		i;

	i = len;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		str[--i] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long	num;
	int		i;

	num = (long)n;
	i = ft_len(num);
	return (build_itoa_str(num, i));
}
/*
int	main(void)
{
	int	num[] = {42, -42, 0, 123456, -98765};
	int	test = sizeof(num) / sizeof(num[0]);
	char	*result;
	int	i;
	
	i = 0;
	while (i < test)
	{
		result = ft_itoa(num[i]);
		printf("Originale: %d -> Convertita: %s\n", num[i], result);
		free(result);
	}
	return (0);
}*/
