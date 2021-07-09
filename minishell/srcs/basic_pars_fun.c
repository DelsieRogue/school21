/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_pars_fun.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:39:14 by drogue            #+#    #+#             */
/*   Updated: 2021/05/23 16:41:17 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int		my_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*char_add(char *str, char c)
{
	char	*pi;
	int		i;
	int		len;

	i = 0;
	len = my_strlen(str);
	pi = (char *)malloc(sizeof(char) * (len + 2));
	ft_memcpy(pi, str, len);
	pi[len] = c;
	pi[len + 1] = '\0';
	if (str)
		free(str);
	return (pi);
}

char	**p_add(char **mas)
{
	char	**pi;
	int		i;

	i = 0;
	pi = (char **)malloc(sizeof(char *) * (ft_strlen_mas(mas) + 2));
	while (i < ft_strlen_mas(mas))
	{
		pi[i] = mas[i];
		i++;
	}
	pi[i] = NULL;
	pi[i + 1] = NULL;
	if (mas)
		free(mas);
	return (pi);
}

int		char_join(t_pars *pars, char c)
{
	pars->arg[pars->n] = char_add(pars->arg[pars->n], c);
	pars->i++;
	return (0);
}

int		p_join(t_pars *pars, char *str)
{
	while (str[pars->i] == ' ')
	{
		pars->i++;
		if (str[pars->i] == '\0')
			return (0);
	}
	pars->arg = p_add(pars->arg);
	pars->n++;
	return (0);
}
