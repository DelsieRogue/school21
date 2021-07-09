/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:17:36 by drogue            #+#    #+#             */
/*   Updated: 2020/11/10 13:26:08 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *pi;

	if (*lst && lst)
	{
		pi = *lst;
		while (pi->next)
			pi = pi->next;
		pi->next = new;
	}
	else
		*lst = new;
}
