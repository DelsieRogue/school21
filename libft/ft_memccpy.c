/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:09:46 by drogue            #+#    #+#             */
/*   Updated: 2020/11/06 12:37:39 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char *pi;
	char *pi2;
	char ch;

	ch = (char)c;
	pi = (char *)dst;
	pi2 = (char *)src;
	while (n--)
	{
		*pi = *pi2;
		dst++;
		if (*pi2 == ch)
			return (dst);
		pi++;
		pi2++;
	}
	return (0);
}
