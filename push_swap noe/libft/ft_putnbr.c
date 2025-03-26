/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npezzati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:48:50 by npezzati          #+#    #+#             */
/*   Updated: 2024/12/02 14:48:53 by npezzati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	int	num;

	num = 0;
	if (n == -2147483648)
	{
		return (ft_putstr("-2147483648"));
	}
	if (n < 0)
	{
		num += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		num += ft_putnbr(n / 10);
		num += ft_putnbr(n % 10);
	}
	else
		num += ft_putchar(n + 48);
	return (num);
}
