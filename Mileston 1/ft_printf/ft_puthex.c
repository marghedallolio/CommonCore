/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:35:30 by mdalloli          #+#    #+#             */
/*   Updated: 2024/11/29 14:35:33 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

int	ft_puthex(unsigned long n, int upp)
{
	int		len;
	char	*base;

	if (upp)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		len += ft_puthex(n / 16, upp);
	len += ft_putchar(base[n % 16]);
	return (len);
}
