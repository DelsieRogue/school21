/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:38:29 by bshawnee          #+#    #+#             */
/*   Updated: 2021/05/01 04:18:32 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_buf(char *buf, char **line)
{
	char	*new_buf;

	if (buf)
	{
		if ((ft_strchr(buf, '\n')))
		{
			new_buf = ft_strdup(ft_strchr(buf, '\n') + 1);
			*(ft_strchr(buf, '\n')) = '\0';
			free(*line);
			*line = ft_strdup(buf);
			free(buf);
			buf = NULL;
			return (new_buf);
		}
		else
		{
			free(*line);
			*line = ft_strdup(buf);
			free(buf);
			buf = NULL;
		}
	}
	return (NULL);
}

int		get_next_line(int fd, char **line)
{
	int			return_value;
	char		buf[BUFFER_SIZE + 1];
	static char	*remain;
	char		*tmp;

	if ((return_value = read(fd, buf, 0)) < 0 || BUFFER_SIZE < 1)
		return (-1);
	*line = ft_strdup("");
	remain = check_buf(remain, line);
	while (!remain && (return_value = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[return_value] = '\0';
		if ((tmp = ft_strchr(buf, '\n')))
		{
			remain = ft_strdup(tmp + 1);
			*tmp = '\0';
		}
		if (!(*line = ft_strjoins(*line, buf)))
			return (-1);
	}
	if (remain)
		return (1);
	if (return_value <= 0)
		return (0);
	return (1);
}
