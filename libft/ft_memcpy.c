/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:13:03 by drogue            #+#    #+#             */
/*   Updated: 2020/11/06 12:10:25 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *pi;
	unsigned char *pi2;

	pi = (unsigned char *)dst;
	pi2 = (unsigned char *)src;
	if (pi == 0 && pi2 == 0)
		return (dst);
	while (n--)
	{
		*pi = *pi2;
		pi++;
		pi2++;
	}
	return (dst);
}
