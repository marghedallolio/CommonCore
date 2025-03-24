/*Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*dest;

	if (min >= max)
		return (NULL);
	dest = malloc((max - min) * sizeof(int));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (min < max)
	{
		dest[i] = min;
		min++;
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	int	*range;
	int	i;
	int	min;
	int	max;

	min = 4;
	max = 7;
	i = 0;
	range = ft_range(min, max);
	if (range != NULL)
	{
		while (i < (max - min))
		{
			printf("%d\n", range[i]);
			i++;
		}
		free(range);
	}
	else
		printf("Invalid range or memory allocation failed\n");
	return (0);
}*/