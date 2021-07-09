/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_for_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:00:06 by bshawnee          #+#    #+#             */
/*   Updated: 2021/05/27 14:46:51 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static char	*check(char const *s1, char const *s2)
{
	if (!s1)
	{
		if (!s2)
			return (NULL);
		return (ft_strdup(s2));
	}
	if (!s2)
	{
		if (!s1)
			return (NULL);
		return (ft_strdup(s1));
	}
	return (NULL);
}

void		set_old_pwd(void)
{
	t_env *tmp;

	tmp = g_list_env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->env->key, "OLDPWD"))
		{
			free(tmp->env->value);
			tmp->env->value = ft_strdup(find_env_value("PWD"));
			break ;
		}
		tmp = tmp->next;
	}
}

char		*strjoin_cd(char const *s1, char const *s2, int clear_s1)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (check(s1, s2));
	str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	if (!clear_s1)
		str[i] = '/';
	i += 1;
	if (clear_s1)
		free((void*)s1);
	while (s2[++j])
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void		set_env_pwd(void)
{
	char	**tmp;
	char	*tmp_pwd;
	int		trash;

	tmp_pwd = get_pwd();
	tmp = malloc(sizeof(char*) * 2);
	tmp[1] = NULL;
	tmp[0] = ft_strjoin("PWD=", tmp_pwd);
	free(tmp_pwd);
	free(tmp[0]);
	export(tmp, &trash);
	free(tmp);
}

void		change_pwd(void)
{
	t_env *tmp;

	tmp = g_list_env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->env->key, "PWD"))
		{
			tmp->env->value = ft_strjoins(tmp->env->value, "/.");
			break ;
		}
		tmp = tmp->next;
	}
}
