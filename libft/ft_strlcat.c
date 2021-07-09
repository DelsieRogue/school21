/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:43:45 by drogue            #+#    #+#             */
/*   Updated: 2020/11/06 12:08:19 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;
	int		j;

	j = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = len_dst;
	if (len_dst < (dstsize - 1) && dstsize > 0)
	{
		while (dstsize != i + 1 && src[j])
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	if (len_dst >= dstsize)
		len_dst = dstsize;
	return (len_dst + len_src);
}
