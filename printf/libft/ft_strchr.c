/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:03:24 by drogue            #+#    #+#             */
/*   Updated: 2020/11/06 12:24:49 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char ch;

	ch = (char)c;
	if (!ft_isascii(c))
		return (0);
	while (*s && *s != ch)
		s++;
	if (*s == ch)
		return ((char *)s);
	return (0);
}
