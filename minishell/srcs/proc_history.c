/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:17:01 by drogue            #+#    #+#             */
/*   Updated: 2021/05/23 16:49:57 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	his_add(char ***mas, char *line)
{
	char	**pi;
	int		i;

	i = 0;
	pi = (char **)malloc(sizeof(char *) * (ft_strlen_mas(*mas) + 2));
	while (i < ft_strlen_mas(*mas))
	{
		pi[i] = (*mas)[i];
		i++;
	}
	pi[i] = line;
	pi[i + 1] = NULL;
	free(*mas);
	*mas = NULL;
	*mas = pi;
	return (0);
}

int	set_history(t_his *his)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(".minishell_history", O_RDWR);
	while (i < ft_strlen_mas(his->his))
	{
		write(fd, his->his[i], ft_strlen(his->his[i]));
		write(fd, "\n", 1);
		i++;
	}
	close(fd);
	return (0);
}

int	get_history(t_his *his)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(".minishell_history", O_CREAT | O_APPEND |
		O_RDWR, S_IWRITE | S_IREAD);
	while (get_next_line(fd, &line) == 1)
		his_add(&his->his, line);
	free_str(&line);
	close(fd);
	return (0);
}
