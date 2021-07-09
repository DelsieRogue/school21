/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 13:56:20 by bshawnee          #+#    #+#             */
/*   Updated: 2021/05/27 18:55:23 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strldup(const char *str, size_t len)
{
	char			*new_str;
	size_t			i;

	i = 0;
	if (!(new_str = (char*)malloc(len + 1)))
		return (NULL);
	while (i < len && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	if (len == i)
		new_str[len] = 0;
	else
		new_str[i] = 0;
	return (new_str);
}
