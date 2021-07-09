/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:25:57 by drogue            #+#    #+#             */
/*   Updated: 2020/11/11 17:50:22 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_list;
	t_list *tem_value;

	new_list = NULL;
	if (!lst || !f)
		return (0);
	while (lst->next != NULL)
	{
		if (!(tem_value = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&new_list, del);
			return (0);
		}
		tem_value->content = (*f)(lst->content);
		ft_lstadd_back(&new_list, tem_value);
		lst = lst->next;
	}
	if (!(tem_value = ft_lstnew((*f)(lst->content))))
	{
		ft_lstclear(&new_list, del);
		return (0);
	}
	tem_value->content = (*f)(lst->content);
	ft_lstadd_back(&new_list, tem_value);
	return (new_list);
}
