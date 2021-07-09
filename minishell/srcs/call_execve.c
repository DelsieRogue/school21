/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:53:33 by drogue            #+#    #+#             */
/*   Updated: 2021/05/27 17:01:54 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	signal_c(int a)
{
	a++;
	write(1, "\n", 1);
}

void	signal_q(int a)
{
	a++;
	write(1, "Quit: 3", 7);
	write(1, "\n", 1);
}

int		call_execve(t_data *arg, char *s, int *ex)
{
	char	**env;
	pid_t	i;
	int		status;

	i = fork();
	signal(SIGINT, signal_c);
	signal(SIGQUIT, signal_q);
	if (i == 0)
	{
		env = list_to_arr(g_list_env);
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		execve(s, arg->mas, env);
		exit(errno);
	}
	waitpid(i, &status, 0);
	*ex = WEXITSTATUS(status);
	if (WIFSIGNALED(status) && WTERMSIG(status))
		*ex = 128 + WTERMSIG(status);
	return (*ex);
}

int		check_path(char *path)
{
	char	**mas;
	int		ret;

	ret = 0;
	mas = ft_split(path, '/');
	if (ft_strlen_mas(mas) > 1)
		ret = 1;
	free_two_mas(&mas, ft_strlen_mas(mas));
	return (ret);
}

int		proc_execve(t_data *arg, int *ex)
{
	char	**path;
	int		i;

	i = 0;
	path = NULL;
	path = ft_split(find_env_value("PATH"), ':');
	while (path && path[i])
	{
		path[i] = my_strjoin(my_strjoin(path[i], "/"), arg->mas[0]);
		i++;
	}
	if (check_path(arg->mas[0]) || !find_env_value("PATH"))
	{
		path = p_add(path);
		path[i] = ft_strdup(arg->mas[0]);
	}
	i = 0;
	while (path && path[i] && call_execve(arg, path[i], ex) == 2)
		i++;
	free_two_mas(&path, ft_strlen_mas(path));
	return (0);
}
