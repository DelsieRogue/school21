/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 15:03:32 by drogue            #+#    #+#             */
/*   Updated: 2020/11/10 14:41:15 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_find_char(char s1, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*pi;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 || !set)
		return (0);
	k = -1;
	i = 0;
	j = ft_strlen(s1);
	while (ft_find_char(s1[i], set) && s1[i])
		i++;
	while (ft_find_char(s1[--j], set))
	{
		if (i >= j)
			return (ft_calloc(1, sizeof(char)));
	}
	if (!(pi = malloc((j - i + 2) * sizeof(char))))
		return (0);
	pi[j - i + 1] = 0;
	while (i < j + 1)
		pi[++k] = s1[i++];
	return (pi);
}
