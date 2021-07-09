/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:36:29 by drogue            #+#    #+#             */
/*   Updated: 2020/11/26 13:49:53 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		full_free(char **line, char **res, char **buf)
{
	if (line && *line)
	{
		free(*line);
		*line = NULL;
	}
	if (res && *res)
	{
		free(*res);
		*res = NULL;
	}
	if (buf && *buf)
	{
		free(*buf);
		*buf = NULL;
	}
	return (-1);
}

int		ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1, char **res)
{
	char	*pi;
	int		i;

	i = 0;
	if (!s1)
		return (0);
	pi = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!pi)
		return (0);
	while (s1[i])
	{
		pi[i] = s1[i];
		i++;
	}
	pi[i] = 0;
	if (res)
		full_free(res, NULL, NULL);
	return (pi);
}

char	*ft_strchr(char *s, int c)
{
	char ch;

	ch = (char)c;
	while (*s && *s != ch)
		s++;
	if (*s == ch)
		return ((char *)s);
	return (0);
}
