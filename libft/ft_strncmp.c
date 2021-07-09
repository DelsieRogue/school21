/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:25:43 by drogue            #+#    #+#             */
/*   Updated: 2020/11/06 12:03:50 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *pi;
	unsigned char *pi2;

	pi = (unsigned char *)s1;
	pi2 = (unsigned char *)s2;
	while (n-- && (*pi || *pi2))
	{
		if (*pi != *pi2)
			return ((int)(*pi - *pi2));
		pi++;
		pi2++;
	}
	return (0);
}
