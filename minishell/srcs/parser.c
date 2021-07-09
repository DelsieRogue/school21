/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:34:27 by drogue            #+#    #+#             */
/*   Updated: 2021/05/23 19:55:49 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int		parse_string(t_pars *pars, char *s, int *ex)
{
	while (s[pars->i] != '\0')
	{
		if (s[pars->i] == '"')
			read_two_quot(pars, s, ex);
		else if (s[pars->i] == '\'')
			read_one_quot(pars, s);
		else if (s[pars->i] == '\\')
			read_shield(pars, s);
		else if (s[pars->i] == ' ')
			p_join(pars, s);
		else if (s[pars->i] == ';')
			semicolon(pars, s, ex);
		else if (s[pars->i] == '$' && (s[pars->i + 1] == '$' ||
			s[pars->i + 1] == '?' || ft_isalnum(s[pars->i + 1])))
			read_env(pars, s, ex);
		else if (ft_strchr("|><", s[pars->i]))
			add_spec(pars, s, ex);
		else
			char_join(pars, s[pars->i]);
	}
	return (0);
}

void	init_pars(t_pars *pars, t_his *his)
{
	pars->his = his;
	pars->i = 0;
	pars->n = -1;
	pars->arg = NULL;
}

int		proccecing_string(char *str, int *ex, t_his *his)
{
	t_pars pars;

	if (!str)
		return (0);
	init_pars(&pars, his);
	p_join(&pars, str);
	parse_string(&pars, str, ex);
	if (pars.arg && pars.arg[0])
		array_processing(&pars, ex);
	free(pars.arg);
	pars.arg = NULL;
	return (0);
}
