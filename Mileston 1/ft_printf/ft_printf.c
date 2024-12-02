/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:06:08 by mdalloli          #+#    #+#             */
/*   Updated: 2024/11/29 16:06:10 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	tot_len;
	
	tot_len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				tot_len += ft_putchar(va_arg(args, int));
			else if (*format == 's')
				tot_len += ft_putstr(va_arg(args, char *));
			else if (*format == 'p')
				tot_len += ft_putptr(va_arg(args, void *));
			else if (*format == 'd' || *format == 'i')
				tot_len += ft_putnbr(va_arg(args, int));
			else if (*format == 'u')
				tot_len += ft_putunsigned(va_arg(args, unsigned int));
			else if (*format == 'x')
				tot_len += ft_puthex(va_arg(args, unsigned int), 0);
			else if (*format == 'X')
				tot_len += ft_puthex(va_arg(args, unsigned int), 1);
			else if (*format == '%')
				tot_len += ft_putchar('%');
		}
		else
			tot_len += ft_putchar(*format);
		format ++;
	}
	va_end(args);
	return (tot_len);
}
