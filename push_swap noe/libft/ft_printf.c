/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npezzati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:36:05 by npezzati          #+#    #+#             */
/*   Updated: 2024/12/02 14:36:33 by npezzati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_type(char formato, va_list args)
{
	int		len;

	len = 0;
	if (formato == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (formato == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (formato == 'p')
		len += ft_putptr(va_arg(args, void *));
	else if (formato == 'd' || formato == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (formato == 'u')
		len += ft_putunsigned(va_arg(args, unsigned int));
	else if (formato == 'x' || formato == 'X')
		len += ft_puthex(va_arg(args, unsigned int), formato);
	else if (formato == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed_chars;

	va_start(args, format);
	printed_chars = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			printed_chars += ft_type(*format, args);
		}
		else
			printed_chars += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (printed_chars);
}
