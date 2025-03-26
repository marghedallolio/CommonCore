/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npezzati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:36:56 by npezzati          #+#    #+#             */
/*   Updated: 2024/11/23 10:36:59 by npezzati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_convert(char *i_to_a, unsigned int num, size_t len, int is_neg)
{
	if (is_neg)
	{
		i_to_a[0] = '-';
		while (len > 1)
		{
			len--;
			i_to_a[len] = (num % 10) + '0';
			num /= 10;
		}
	}
	else
	{
		while (len > 0)
		{
			len--;
			i_to_a[len] = (num % 10) + '0';
			num /= 10;
		}
	}
}

char	*ft_itoa(int n)
{
	char			*i_to_a;
	size_t			len;
	unsigned int	num;
	int				is_neg;

	len = ft_nlen(n);
	is_neg = 0;
	i_to_a = (char *)malloc(sizeof(char) * len + 1);
	if (!i_to_a)
		return (NULL);
	i_to_a[len] = '\0';
	if (n < 0)
	{
		is_neg = 1;
		num = -n;
	}
	else
		num = n;
	ft_convert(i_to_a, num, len, is_neg);
	return (i_to_a);
}
