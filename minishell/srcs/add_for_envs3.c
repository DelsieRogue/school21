/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_for_envs3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:57:42 by bshawnee          #+#    #+#             */
/*   Updated: 2021/05/27 15:10:32 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void		add_for_sort(t_env **env, int j, t_env *tmp)
{
	if (ft_strncmp(env[j]->env->key, env[j + 1]->env->key,
	ft_strlen(env[j + 1]->env->key)) >= 0)
	{
		tmp = env[j];
		env[j] = env[j + 1];
		env[j + 1] = tmp;
	}
}

void			sort_env(t_env **env, size_t size)
{
	size_t	i;
	size_t	j;
	t_env	*tmp;
	size_t	k;

	i = -1;
	k = -1;
	tmp = NULL;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - i - 1)
			add_for_sort(env, j, tmp);
	}
	env[i + 1] = NULL;
	while (env[++k])
	{
		if (!env[k]->env->value)
			printf("declare -x %s\n", env[k]->env->key);
		else
			printf("declare -x %s=\"%s\"\n", env[k]->env->key,
				env[k]->env->value);
	}
}

void			print_sorted_envs(t_env *list)
{
	t_env	**nodes;
	t_env	*tmp;
	int		i;

	i = 0;
	tmp = list;
	nodes = NULL;
	if (list_size(list))
	{
		nodes = (t_env**)malloc(sizeof(t_env*) * list_size(list) + 1);
		while (list)
		{
			nodes[i] = list;
			i++;
			list = list->next;
		}
		sort_env(nodes, list_size(g_list_env));
		free(nodes);
	}
}
