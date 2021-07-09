/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:13:01 by bshawnee          #+#    #+#             */
/*   Updated: 2021/05/27 14:48:20 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void		change_old_pwd(void)
{
	t_env *tmp;

	tmp = g_list_env;
	while (tmp)
	{
		if (ft_strcmp(tmp->env->key, "OLDPWD"))
		{
			free(tmp->env->value);
			tmp->env->value = ft_strdup(find_env_value("PWD"));
			break ;
		}
		tmp = tmp->next;
	}
}

int				add_for_abs_path(char **s, const char *str)
{
	if (*s && !ft_strcmp(str, ".."))
	{
		(*ft_strrchr(*s, '/')) = '\0';
		cd(*s);
		free(*s);
		*s = NULL;
		return (0);
	}
	if (!str)
	{
		printf("bash: cd: HOME not set\n");
		return (1);
	}
	if (!ft_strcmp(".", str))
	{
		if (!*s)
			*s = ft_strdup(find_env_value("OLDPWD"));
		change_old_pwd();
		change_pwd();
		printf("cd: error retrieving current directory: getcwd: cannot acces");
		printf("s parent directories: No such file or directory\n");
		return (1);
	}
	printf("bash: cd: No such file or directory\n");
	return (1);
}

static int		correct_abs_path(const char *path, const char *str)
{
	t_env		*tmp;
	static char	*norm_pwd;

	tmp = g_list_env;
	if (chdir(path) == -1)
		return (add_for_abs_path(&norm_pwd, str));
	while (tmp)
	{
		if (!ft_strcmp(tmp->env->key, "PWD"))
		{
			free(tmp->env->value);
			tmp->env->value = ft_strdup(path);
			break ;
		}
		tmp = tmp->next;
	}
	return (0);
}

int				cd(const char *path)
{
	char	*tmp;
	int		ret;

	ret = 0;
	set_old_pwd();
	if (!path)
		ret = correct_abs_path(find_env_value("HOME"), NULL);
	else if (*path == '~')
	{
		tmp = ft_strdup(find_env_value("HOME"));
		tmp = strjoin_cd(tmp, path + 1, 1);
		ret = correct_abs_path(tmp, path);
		free(tmp);
	}
	else if (*path == '/')
		ret = correct_abs_path(path, path);
	else
	{
		tmp = strjoin_cd(find_env_value("PWD"), path, 0);
		ret = correct_abs_path(tmp, path);
		free(tmp);
	}
	set_env_pwd();
	return (ret);
}
