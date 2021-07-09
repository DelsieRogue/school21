/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_for_envs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:50:55 by bshawnee          #+#    #+#             */
/*   Updated: 2021/05/27 15:16:17 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

size_t				list_size(t_env *list)
{
	if (list)
		return (list_size(list->next) + 1);
	return (0);
}

char				*get_value(const char *value)
{
	size_t	i;

	i = 0;
	while (value[i] != '=' && value[i])
		i++;
	if (value[i] == '=')
		return (ft_strdup(&value[i + 1]));
	else
		return (NULL);
}

char				*get_key(const char *key)
{
	size_t	i;

	i = 0;
	if (!ft_strncmp(key, "ITERM_SESSION_ID", ft_strlen("ITERM_SESSION_ID")))
		return (ft_strdup("ITERM_SESSION_ID"));
	while (key[i] && key[i] != '=')
		i++;
	return (ft_strldup(key, i));
}

t_env				*add_list_env(void *key, void *value)
{
	t_env *envs;

	if (!(envs = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	if (!(envs->env = (t_tuple*)malloc(sizeof(t_tuple))))
		return (NULL);
	envs->env->key = key;
	envs->env->value = value;
	envs->next = NULL;
	return (envs);
}

void				get_list_env(void)
{
	extern char	**environ;
	int			i;
	t_env		*tmp;

	i = 1;
	tmp = add_list_env(get_key(environ[0]), get_value(environ[0]));
	g_list_env = tmp;
	while (environ[i])
	{
		tmp->next = add_list_env(get_key(environ[i]), get_value(environ[i]));
		tmp = tmp->next;
		i++;
	}
}
