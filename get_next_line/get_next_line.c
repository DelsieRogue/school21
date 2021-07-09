/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:16:45 by drogue            #+#    #+#             */
/*   Updated: 2020/11/25 03:52:23 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2, char **s3)
{
	char	*pi;
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	pi = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!pi)
		return (0);
	pi[len_s1 + len_s2] = 0;
	while (i < len_s1 + len_s2)
	{
		if (i < len_s1)
			pi[i] = s1[i];
		if (i >= len_s1 && i < len_s1 + len_s2)
			pi[i] = s2[j++];
		i++;
	}
	full_free(s3, NULL, NULL);
	return (pi);
}

int		check_buffer(char **buf, char **line, char **res)
{
	char *pi;

	if (ft_strlen(*buf) != BUFFER_SIZE && !(pi = ft_strchr(*buf, '\n')))
	{
		if (!(*line = ft_strjoin(*line, *buf, line)))
			return (full_free(line, res, buf));
		return (0);
	}
	if ((pi = ft_strchr(*buf, '\n')))
	{
		*pi = '\0';
		if (!(*res = ft_strdup(pi + 1, res)))
			return (full_free(line, res, buf));
		if (!(*line = ft_strjoin(*line, *buf, line)))
			return (full_free(line, res, buf));
		return (1);
	}
	return (-1);
}

int		buffer_parse(char **buf, char **line, char **res, int fd)
{
	int	i;

	if (!(*buf))
	{
		if (!(*buf = malloc(BUFFER_SIZE + 1)))
			return (full_free(line, res, NULL));
		(*buf)[BUFFER_SIZE] = 0;
	}
	while ((i = read(fd, *buf, BUFFER_SIZE)) == BUFFER_SIZE &&
	!(ft_strchr(*buf, '\n')))
	{
		if (!(*line = ft_strjoin(*line, *buf, line)))
			return (full_free(line, res, buf));
	}
	if (i == 0)
	{
		if (!(*line = ft_strjoin(*line, "\0", line)))
			return (full_free(line, res, buf));
		return (0);
	}
	if (i == -1)
		return (full_free(line, res, buf));
	(*buf)[i] = '\0';
	return (check_buffer(buf, line, res));
}

int		check_res(char **line, char **res)
{
	char	*pi;

	if ((pi = ft_strchr(*res, '\n')))
	{
		*pi = '\0';
		if (!(*line = ft_strdup(*res, NULL)))
			return (full_free(line, res, NULL));
		if (!(*res = ft_strdup(pi + 1, res)))
			return (full_free(line, res, NULL));
		return (1);
	}
	if (!(*line = ft_strdup(*res, res)))
		return (full_free(line, res, NULL));
	full_free(res, NULL, NULL);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*res;
	char		*buf;
	int			ret_r;
	int			ret_b;
	int			i;

	i = 0;
	*line = NULL;
	buf = NULL;
	if (res)
	{
		ret_r = check_res(line, &res);
		if (ret_r != 0)
			return (ret_r);
	}
	ret_b = buffer_parse(&buf, line, &res, fd);
	full_free(NULL, NULL, &buf);
	if (ret_b == 0)
		full_free(&res, NULL, NULL);
	return (ret_b);
}
