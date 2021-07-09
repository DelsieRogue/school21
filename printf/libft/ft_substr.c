/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:58:06 by drogue            #+#    #+#             */
/*   Updated: 2020/11/10 16:27:19 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*pi;
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	pi = (char *)malloc(sizeof(char) * (len + 1));
	if (!pi)
		return (0);
	if (start < ft_strlen(s) - 1)
	{
		while (s[start] && i != len)
		{
			pi[i] = s[start];
			start++;
			i++;
		}
		pi[i] = 0;
	}
	else
		pi[i] = 0;
	return (pi);
}
