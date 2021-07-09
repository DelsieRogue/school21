/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 22:11:45 by drogue            #+#    #+#             */
/*   Updated: 2020/11/07 22:29:00 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*pi;

	pi = *lst;
	if (!lst || !*lst)
		return ;
	while ((pi->next) != NULL)
	{
		(*del)(pi->content);
		pi = pi->next;
		free(*lst);
		*lst = pi;
	}
	(*del)(pi->content);
	free(*lst);
	*lst = NULL;
}
