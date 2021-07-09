/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:41:22 by drogue            #+#    #+#             */
/*   Updated: 2020/11/06 17:28:08 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				znak;
	unsigned long	rez;

	i = 0;
	znak = 1;
	rez = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == ' ' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		znak = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		rez = 10 * rez + str[i] - '0';
		if (rez > 2147483647 && znak == 1)
			return (-1);
		if (rez > 2147483648 && znak == -1)
			return (0);
		i++;
	}
	return ((int)(rez) * znak);
}
