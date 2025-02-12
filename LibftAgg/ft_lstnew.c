/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:07:07 by mdalloli          #+#    #+#             */
/*   Updated: 2024/11/26 15:07:10 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
int	main(void)
{
	char	*str;
	t_list	*node;

	str = "spero sia giusto";
	node = ft_lstnew(str);
	if (!node)
	{
		printf("Errore nella creazione del nodo.\n");
		return (1);
	}
	printf("contenuto del nodo: %s\n", (char *)node->content);
	free(node);
	return (0);
}*/
