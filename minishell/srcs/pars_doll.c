/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_doll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:46:43 by drogue            #+#    #+#             */
/*   Updated: 2021/05/23 18:40:25 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int		parse_doll(t_pars *pars, char *pi, int *ex)
{
	int i;

	i = pars->i;
	pars->i = 0;
	parse_string(pars, pi, ex);
	pars->i = i;
	return (0);
}

int		check_first_simvol(t_pars *pars, char *s, int *ex)
{
	char *pi;

	if (ft_isdigit(s[pars->i]))
	{
		pars->i++;
		return (0);
	}
	if (s[pars->i] == '?')
	{
		pi = ft_itoa(*ex);
		pars->arg[pars->n] = my_strjoin(pars->arg[pars->n], pi);
		free(pi);
		pars->i++;
		return (0);
	}
	return (1);
}

int		read_env(t_pars *pars, char *s, int *ex)
{
	char	*pi;
	char	*tmp;
	int		l;

	l = 0;
	pars->i++;
	if (!check_first_simvol(pars, s, ex))
		return (0);
	while (ft_isalnum(s[pars->i + l]))
		l++;
	if ((tmp = ft_strldup(s + pars->i, l)))
	{
		if ((pi = find_env_value(tmp)))
			parse_doll(pars, pi, ex);
	}
	free(tmp);
	pars->i += l;
	while (s[pars->i] == ' ' && s[pars->i])
		pars->i++;
	return (0);
}
