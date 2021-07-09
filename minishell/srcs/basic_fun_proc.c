/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_fun_proc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:50:42 by drogue            #+#    #+#             */
/*   Updated: 2021/05/23 16:52:56 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int		free_in_mas(char **mas)
{
	int i;

	i = 0;
	while (mas[i])
	{
		if (mas[i])
			free(mas[i]);
		i++;
	}
	return (0);
}

char	*my_strjoin(char *s1, char *s2)
{
	char	*pi;
	int		i;
	int		len;

	i = 0;
	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	pi = malloc(len + 1);
	pi[len] = '\0';
	while (s1[i])
	{
		pi[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		pi[i] = *s2;
		i++;
		s2++;
	}
	free(s1);
	s1 = NULL;
	return (pi);
}

int		free_two_mas(char ***mas, int n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		if ((*mas)[i])
			free((*mas)[i]);
		(*mas)[i] = NULL;
		i++;
	}
	free(*mas);
	*mas = NULL;
	return (0);
}

int		ft_strlen_mas(char **s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

int		add_new_str(char *s, char ***mas)
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
	pi[i] = s;
	pi[i + 1] = NULL;
	free(*mas);
	*mas = NULL;
	*mas = pi;
	return (0);
}
