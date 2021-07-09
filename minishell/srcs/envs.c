/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:25:28 by bshawnee          #+#    #+#             */
/*   Updated: 2021/05/27 15:07:21 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static char	*compare_str(char *src, t_tuple *pair)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	while (pair->key[i])
	{
		src[i] = pair->key[i];
		++i;
	}
	src[i++] = '=';
	while (pair->value[j])
	{
		src[i] = pair->value[j];
		i++;
		j++;
	}
	return (src);
}

char		**list_to_arr(t_env *env)
{
	char	**arr;
	size_t	i;
	size_t	size;

	size = list_size(env);
	i = 0;
	arr = (char**)malloc(sizeof(char*) * size);
	if (!arr)
		return (NULL);
	while (env)
	{
		arr[i] = (char*)malloc(ft_strlen(env->env->key) +\
		ft_strlen(env->env->value) + 1);
		arr[i][ft_strlen(env->env->key) + ft_strlen(env->env->value) + 1] = 0;
		arr[i] = compare_str(arr[i], env->env);
		env = env->next;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

t_env		*search_key(const char *key)
{
	t_env *tmp;

	tmp = g_list_env;
	while (tmp)
	{
		if (ft_strcmp(tmp->env->key, key) != 0)
			tmp = tmp->next;
		else
			return (tmp);
	}
	return (NULL);
}

void		add_export(char *s)
{
	char	*key;
	char	*value;
	t_env	*pi;

	key = get_key(s);
	value = get_value(s);
	if ((pi = search_key(key)))
	{
		if (value)
		{
			free(pi->env->value);
			free(pi->env->key);
			pi->env->value = value;
			pi->env->key = key;
		}
		else
		{
			free(key);
			free(value);
		}
	}
	else
		add_environ(key, value);
}

void		export(char **args, int *ex)
{
	int	i;

	i = 0;
	if (!*args)
		return (print_sorted_envs(g_list_env));
	while (args[i])
	{
		if (!ft_strncmp("=", args[i], 1) && (*ex = 1))
			printf("bash: export: `%s': not a valid identifier\n", args[i]);
		else
			add_export(args[i]);
		i++;
	}
}
