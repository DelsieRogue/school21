/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:59:35 by drogue            #+#    #+#             */
/*   Updated: 2021/02/16 21:28:49 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

t_list	*ft_lstnew_2(void *content)
{
	t_list *ps;

	if (!(ps = malloc(sizeof(t_list))))
		return (NULL);
	ps->content = ft_strdup(content);
	ps->next = NULL;
	return (ps);
}

int		add_elem_list(t_list **file, char *line)
{
	t_list *tmp;

	if (*line != '\0' || ft_lstsize(*file) > 8)
	{
		if ((tmp = ft_lstnew_2(line)) == NULL)
			return (6);
		ft_lstadd_back(file, tmp);
	}
	return (0);
}

int		filling_list(t_list **file, t_data *data)
{
	char	*line;
	int		error;

	while ((error = get_next_line(data->fd, &line)) != 0)
	{
		if (error == -1)
			return (5);
		if ((error = add_elem_list(file, line)) != 0)
			return (error);
		free(line);
		line = NULL;
	}
	if ((error = add_elem_list(file, line)) != 0)
		return (error);
	free(line);
	line = NULL;
	return (0);
}
