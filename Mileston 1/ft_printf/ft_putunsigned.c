/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:56:18 by mdalloli          #+#    #+#             */
/*   Updated: 2024/11/29 14:56:20 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

int	ft_putunsigned(unsigned int n)
{
	unsigned int	len;
	char	c;

	len = 0;
	if (n == -2147483648)
		return (ft_pustr("-2147483648");
	if(n < 0)
	{
		len += ft_puchar('-');
		n = -n;
	}
	if (n > 9)
		len += ft_putnbr(n / 10);
	c = (n % 10) + '0';
	len += ft_puchar(c);
	return (len);
}
