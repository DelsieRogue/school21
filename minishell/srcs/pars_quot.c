/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_quot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:42:05 by drogue            #+#    #+#             */
/*   Updated: 2021/05/23 16:44:01 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int		read_shield(t_pars *pars, char *s)
{
	pars->i++;
	if (s[pars->i] == '\0')
		return (0);
	char_join(pars, s[pars->i]);
	return (0);
}

int		read_shield_2(t_pars *pars, char *s)
{
	if (s[pars->i + 1] == '"' || s[pars->i + 1] == '$' ||
		s[pars->i + 1] == '\\')
		pars->i++;
	char_join(pars, s[pars->i]);
	return (0);
}

int		read_two_quot(t_pars *pars, char *s, int *ex)
{
	pars->i++;
	if (s[pars->i - 2] == ' ' && s[pars->i] == '"')
	{
		free(pars->arg[pars->n]);
		pars->n--;
	}
	else
	{
		while (s[pars->i] != '\0' && s[pars->i] != '"')
		{
			if (s[pars->i] == '\\')
				read_shield_2(pars, s);
			else if (s[pars->i] == '$' && s[pars->i + 1] != '"' &&
				(s[pars->i + 1] == '$' || s[pars->i + 1] == '?' ||
					ft_isalnum(s[pars->i + 1])))
				read_env(pars, s, ex);
			else
				char_join(pars, s[pars->i]);
		}
	}
	if (s[pars->i] == '"')
		pars->i++;
	return (0);
}

int		read_one_quot(t_pars *pars, char *s)
{
	pars->i++;
	while (s[pars->i] != '\'' && s[pars->i] != '\0')
		char_join(pars, s[pars->i]);
	if (s[pars->i] == '\'')
		pars->i++;
	return (0);
}
