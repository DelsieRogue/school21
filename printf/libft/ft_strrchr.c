/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:43:16 by drogue            #+#    #+#             */
/*   Updated: 2020/11/05 11:59:00 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char ch;
	char *pi;

	ch = (char)c;
	pi = 0;
	if (!ft_isascii(c))
		return (0);
	while (*s)
	{
		if (*s == ch)
			pi = (char *)s;
		s++;
	}
	if (ch == '\0')
	{
		pi = (char *)s;
		return (pi);
	}
	if (pi)
		return (pi);
	return (0);
}
