/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_spec_simvols.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:45:11 by drogue            #+#    #+#             */
/*   Updated: 2021/05/23 16:45:58 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int		check_begin(t_pars *pars, char *s, int *ex, char c)
{
	char s1[2];

	if ((!pars->arg[0] && (s[pars->i] == c)) ||
		(s[pars->i] == c && s[pars->i + 1] == c))
	{
		*ex = 258;
		if (!c)
			error(s, ex);
		else
		{
			s1[0] = c;
			s1[1] = '\0';
			error(s1, ex);
		}
		*s = '\0';
		while (s[pars->i])
			pars->i++;
		free_two_mas(&pars->arg, ft_strlen_mas(pars->arg));
		return (1);
	}
	return (0);
}

void	add_spec(t_pars *pars, char *s, int *ex)
{
	if (check_begin(pars, s, ex, '|'))
		return ;
	if (pars->arg[pars->n])
		p_join(pars, s);
	char_join(pars, s[pars->i]);
	if (s[pars->i] == '>')
		char_join(pars, s[pars->i]);
	p_join(pars, s);
}

int		semicolon(t_pars *pars, char *s, int *ex)
{
	int i;

	i = 0;
	if (check_begin(pars, s, ex, ';'))
		return (1);
	array_processing(pars, ex);
	free(pars->arg);
	pars->arg = NULL;
	pars->n = -1;
	pars->i++;
	p_join(pars, s);
	return (0);
}
