/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:33:36 by drogue            #+#    #+#             */
/*   Updated: 2020/11/06 13:10:14 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*p;

	if (!s || !f)
		return (0);
	i = ft_strlen(s);
	if (!(p = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (s[i])
	{
		p[i] = (*f)((unsigned int)i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
