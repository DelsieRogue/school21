/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:28:48 by drogue            #+#    #+#             */
/*   Updated: 2020/11/06 12:09:58 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *pi;
	unsigned char *pi2;

	pi = (unsigned char *)dst;
	pi2 = (unsigned char *)src;
	if (pi == 0 && pi2 == 0)
		return (dst);
	if (src < dst)
	{
		while (len--)
			pi[len] = pi2[len];
		return (dst);
	}
	else
	{
		while (len--)
		{
			*pi = *pi2;
			pi++;
			pi2++;
		}
	}
	return (dst);
}
