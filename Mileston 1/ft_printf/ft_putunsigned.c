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
	int		len;
	char	c;

	len = 0;
	if (n >= 10)
		len += ft_putunsigned(n / 10);
	c = (n % 10) + '0';
	len += ft_puchar(c);
	return (len);
}
