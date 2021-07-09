/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:41:22 by drogue            #+#    #+#             */
/*   Updated: 2021/02/16 22:28:19 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	my_atoi(const char *str)
{
	int				i;
	unsigned long	rez;

	i = 0;
	rez = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == ' ' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		rez = 10 * rez + str[i] - '0';
		if (rez > 100000)
			return (100000);
		i++;
	}
	return ((int)(rez));
}
