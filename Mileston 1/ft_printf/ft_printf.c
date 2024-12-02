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

#include "ft_printf.h"

static int	ft_handle_conversion(char specifier, va_list args)
{
	int	len;

	len = 0;
	if (specifier == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (specifier == 'p')
		len += ft_putptr(va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		len += ft_putunsigned(va_arg(args, unsigned int));
	else if (specifier == 'x')
		len += ft_puthex(va_arg(args, unsigned int), 0);
	else if (specifier == 'X')
		len += ft_puthex(va_arg(args, unsigned int), 1);
	else if (specifier == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		tot_len;

	tot_len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			tot_len += ft_handle_conversion(*format, args);
		}
		else
			tot_len += ft_putchar(*format);
		format ++;
	}
	va_end(args);
	return (tot_len);
}
