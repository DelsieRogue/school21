/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:48:07 by drogue            #+#    #+#             */
/*   Updated: 2020/11/06 12:35:14 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *pi;
	unsigned char *pi2;

	pi = (unsigned char *)s1;
	pi2 = (unsigned char *)s2;
	while (n--)
	{
		if (*pi != *pi2)
			return ((int)(*pi - *pi2));
		pi++;
		pi2++;
	}
	return (0);
}
