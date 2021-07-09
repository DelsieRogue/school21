/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_for_envs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:54:36 by bshawnee          #+#    #+#             */
/*   Updated: 2021/05/27 15:08:49 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char		*find_env_value(const char *key)
{
	t_env *tmp;

	tmp = g_list_env;
	while (tmp)
	{
		if (!ft_strcmp(key, tmp->env->key))
			return (tmp->env->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void		add_environ(const char *key, const char *value)
{
	t_env *tmp;

	tmp = g_list_env;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = add_list_env((void*)key, (void*)value);
}

int			unset_del_item(t_env *tmp, t_env *prev, char *key)
{
	if (!ft_strcmp(key, tmp->env->key))
	{
		if (prev)
		{
			prev->next = tmp->next;
			free_str(&tmp->env->key);
			free_str(&tmp->env->value);
			free(tmp->env);
			free(tmp);
		}
		else
		{
			prev = g_list_env;
			g_list_env = g_list_env->next;
			free_str(&prev->env->key);
			free_str(&prev->env->value);
			free(prev->env);
			free(prev);
		}
		return (0);
	}
	return (1);
}

int			unset(char **keys)
{
	t_env	*tmp;
	t_env	*prev;
	int		i;

	i = 0;
	while (keys[i])
	{
		tmp = g_list_env;
		prev = NULL;
		while (tmp)
		{
			if (!unset_del_item(tmp, prev, keys[i]))
				break ;
			prev = tmp;
			tmp = tmp->next;
		}
		i++;
	}
	return (0);
}

void		print_env(void)
{
	t_env *tmp;

	tmp = g_list_env;
	while (tmp)
	{
		if (tmp->env->value)
			printf("%s=%s\n", tmp->env->key, tmp->env->value);
		tmp = tmp->next;
	}
}
