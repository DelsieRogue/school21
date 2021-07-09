/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_history.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:29:46 by drogue            #+#    #+#             */
/*   Updated: 2021/05/23 16:30:25 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	press_up(t_read *g_s, t_his *his)
{
	if (his->i_his == 0)
		return ;
	if (!his->check++)
		his->tmp_his = g_s->str;
	else
		free_str(&g_s->str);
	his->i_his--;
	g_s->str = ft_strdup(his->his[his->i_his]);
	tputs(restore_cursor, 1, ft_putchar);
	tputs(tigetstr("ed"), 1, ft_putchar);
	write(1, g_s->str, ft_strlen(g_s->str));
	g_s->index = 10 + ft_strlen(g_s->str);
}

void	press_down(t_read *g_s, t_his *his)
{
	if (his->i_his == ft_strlen_mas(his->his))
		return ;
	his->i_his++;
	tputs(restore_cursor, 1, ft_putchar);
	tputs(tigetstr("ed"), 1, ft_putchar);
	free_str(&g_s->str);
	if (his->i_his == ft_strlen_mas(his->his))
	{
		g_s->str = his->tmp_his;
		his->tmp_his = NULL;
		his->check = 0;
	}
	else
		g_s->str = ft_strdup(his->his[his->i_his]);
	g_s->index = 10;
	if (g_s->str)
		g_s->index += write(1, g_s->str, ft_strlen(g_s->str));
}
