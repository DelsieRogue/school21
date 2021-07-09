/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:34:13 by drogue            #+#    #+#             */
/*   Updated: 2020/10/29 15:49:32 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *pi;
	unsigned char a;

	a = (unsigned char)c;
	pi = (unsigned char *)s;
	while (n--)
	{
		if (*pi == a)
			return (pi);
		pi++;
	}
	return (0);
}
