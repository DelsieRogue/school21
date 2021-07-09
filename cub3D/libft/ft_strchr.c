/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:03:24 by drogue            #+#    #+#             */
/*   Updated: 2020/12/22 13:59:52 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char ch;

	ch = (char)c;
	if (ch == '\0')
		return (0);
	if (!ft_isascii(c))
		return (0);
	while (*s && *s != ch)
		s++;
	if (*s == ch)
		return ((char *)s);
	return (0);
}
