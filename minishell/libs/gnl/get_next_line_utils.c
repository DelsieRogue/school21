/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:01:40 by bshawnee          #+#    #+#             */
/*   Updated: 2021/04/20 20:05:22 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t				ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strchr(const char *str, int ch)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == (unsigned char)ch)
			return ((char*)str + i);
		i++;
	}
	if (ch == '\0')
		return ((char*)str + i);
	return (NULL);
}

char				*ft_strdup(const char *str)
{
	char	*new_str;
	size_t	i;

	i = 0;
	if (!(new_str = (char*)malloc(ft_strlen(str) + 1)))
		return (NULL);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static char			*check(char const *s1, char const *s2)
{
	if (!s1)
	{
		if (!s2)
			return (NULL);
		return (ft_strdup(s2));
	}
	if (!s2)
	{
		if (!s1)
			return (NULL);
		return (ft_strdup(s1));
	}
	return (NULL);
}

char				*ft_strjoins(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (check(s1, s2));
	str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	free((void*)s1);
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
