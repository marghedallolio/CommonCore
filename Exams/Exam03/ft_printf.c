/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:37:47 by mdalloli          #+#    #+#             */
/*   Updated: 2025/03/24 15:37:49 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : ft_printf
Expected files   : ft_printf.c
Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
--------------------------------------------------------------------------------

Write a function named `ft_printf` that will mimic the real printf but
it will manage only the following conversions: s,d and x.

Your function must be declared as follows:

int ft_printf(const char *, ... );

Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
To test your program compare your results with the true printf.

Exemples of the function output:

call: ft_printf("%s\n", "toto");
out: toto$

call: ft_printf("Magic %s is %d", "number", 42);
out: Magic number is 42%

call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
out: Hexadecimal for 42 is 2a$*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return (len);
}

int ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	if (!str)
		return (write(1, "(null)", 7));
	return (write(1, str, ft_strlen(str)));
}

int ft_putnbr(int n)
{
	char c;
	int	len = 0;

	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		len += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		len += ft_putnbr(n / 10);
	c = (n % 10) + '0';
	len += ft_putchar(c);
	return (len);
}

int ft_puthex(unsigned long n)
{
	int len = 0;
	char *base = "0123456789abcdef";

	if (n > 16)
		len += ft_puthex(n / 16);
	len += ft_putchar(base[n % 16]);
	return (len);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int tot_len = 0;
	
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
				tot_len += ft_putstr(va_arg(args, char *));
			else if (*format == 'd')
				tot_len += ft_putnbr(va_arg(args, int));
			else if (*format == 'x')
				tot_len += ft_puthex(va_arg(args, unsigned int));
		}
		else
			tot_len += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (tot_len);
}
