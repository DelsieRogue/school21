/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:25:39 by drogue            #+#    #+#             */
/*   Updated: 2020/11/06 12:09:14 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*pi;
	int		i;

	i = 0;
	pi = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!pi)
		return (0);
	while (s1[i])
	{
		pi[i] = s1[i];
		i++;
	}
	pi[i] = 0;
	return (pi);
}
