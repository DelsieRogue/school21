/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:08:08 by drogue            #+#    #+#             */
/*   Updated: 2020/11/06 18:10:29 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*pi;
	int		i;

	i = 0;
	if (!lst)
		return (i);
	pi = lst;
	while (pi)
	{
		pi = pi->next;
		i++;
	}
	return (i);
}
