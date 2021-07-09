/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:06:40 by bshawnee          #+#    #+#             */
/*   Updated: 2021/05/23 17:54:37 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*get_pwd(void)
{
	char			*buf;
	static size_t	buf_size;

	buf = NULL;
	while (!buf)
	{
		buf_size += 5;
		buf = getcwd(buf, buf_size);
		if (!buf && errno == ERANGE)
			continue ;
		else if (!buf && errno == ENOMEM)
			break ;
		else if (!buf && errno == ENOENT)
		{
			buf = ft_strdup(find_env_value("PWD"));
			break ;
		}
	}
	return (buf);
}

int		print_pwd(void)
{
	char *tmp;

	tmp = get_pwd();
	printf("%s\n", tmp);
	free(tmp);
	return (0);
}
