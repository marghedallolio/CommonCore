/*Assignment name  : do_op
Expected files   : *.c, *.h
Allowed functions: atoi, printf, write
--------------------------------------------------------------------------------

Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %

The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.

You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.

Examples:

$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	check_input(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

char	check_sign(char sign)
{
	if (sign != '*' && sign != '-' && sign != '/' && sign != '+' && sign != '%') 
		return (0);
	return (1);
}

void do_op(char *str1, char op, char *str2)
{
	int n1;
	int n2;
	int result; 
	
	result = 0;
	if(check_input(str1) != 1 || check_input(str2) != 1 || check_sign(op) != 1)
		return ;
	n1 = atoi(str1);
	n2 = atoi(str2);
	if(op == '+')
		result += (n1 + n2);
	if (op == '-')
		result += (n1 - n2);
	if (op == '*')
		result += (n1 * n2);
	if (op == '/')
		result += (n1 / n2);
	if (op == '%')
		result += (n1 % n2);
	printf("%d\n", result);
}
int	main(int argc, char **argv)
{
	if(argc == 4 && argv[2][1] == '\0')
	{
		do_op(argv[1], *argv[2], argv[3]);
	}
	else
		write(1, "\n", 1);
	return (0);
}