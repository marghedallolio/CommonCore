/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:23:07 by mdalloli          #+#    #+#             */
/*   Updated: 2024/11/27 11:23:09 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	new_list = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		new_node = (t_list *)malloc(sizeof(t_list));
		if (!new_node)
		{
			if (new_list)
				ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_node->content = f(lst->content);
		new_node->next = NULL;
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/*
void	*to_uppercase(void *content)
{
	char *str = (char *)content;
	char *new_str = malloc(ft_strlen(str) + 1);
	size_t	i = 0;
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		new_str[i] = (str[i] >= 'a' && str[i] <= 'z') ? str[i] - 32 : str[i];
		i++;
	}
	new_str[ft_strlen(str)] = '\0';
	return (new_str);
}

void	del_content(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("spero")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("sia")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("giusto")));
	printf("Lista originale:\n");
	for (t_list *temp = lst; temp; temp = temp->next)
        	printf("%s\n", (char *)temp->content);
	t_list *mapped_list = ft_lstmap(lst, to_uppercase, del_content);
	printf("\nLista mappata:\n");
	for (t_list *temp = mapped_list; temp; temp = temp->next)
  		printf("%s\n", (char *)temp->content);
	ft_lstclear(&lst, del_content);
	ft_lstclear(&mapped_list, del_content);
	return (0);
}*/
