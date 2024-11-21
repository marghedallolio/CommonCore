/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:58:00 by mdalloli          #+#    #+#             */
/*   Updated: 2024/11/21 10:58:02 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	tot_size;
	void	*ptr;

	tot_size = nmemb * size;
	if (size != 0 && tot_size / size != nmemb)
		return (NULL);
	ptr = malloc(tot_size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, tot_size);
	return (ptr);
}
