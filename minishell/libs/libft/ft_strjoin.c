/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:29:06 by drogue            #+#    #+#             */
/*   Updated: 2020/11/06 13:11:20 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pi;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	pi = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!pi)
		return (0);
	pi[len_s1 + len_s2] = 0;
	while (i < len_s1 + len_s2)
	{
		if (i < len_s1)
			pi[i] = s1[i];
		if (i >= len_s1 && i < len_s1 + len_s2)
			pi[i] = s2[j++];
		i++;
	}
	return (pi);
}
