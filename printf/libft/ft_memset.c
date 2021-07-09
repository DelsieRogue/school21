/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:37:43 by drogue            #+#    #+#             */
/*   Updated: 2020/10/29 11:21:35 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *pi;

	pi = (unsigned char *)b;
	while (len--)
	{
		*pi = (unsigned char)c;
		pi++;
	}
	return (b);
}
