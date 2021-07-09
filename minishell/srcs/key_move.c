/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:28:27 by drogue            #+#    #+#             */
/*   Updated: 2021/05/23 16:29:05 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	press_left(t_read *g_s)
{
	if (g_s->index > 10)
	{
		g_s->index--;
		tputs(cursor_left, 1, ft_putchar);
	}
}

void	press_right(t_read *g_s)
{
	if (g_s->str && g_s->index < 10 + (int)ft_strlen(g_s->str))
	{
		g_s->index++;
		tputs(cursor_right, 1, ft_putchar);
	}
}
