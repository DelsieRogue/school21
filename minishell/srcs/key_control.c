/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:31:34 by drogue            #+#    #+#             */
/*   Updated: 2021/05/27 18:53:14 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	press_backspace(t_read *g_s)
{
	char *tmp;

	if (g_s->index == 10)
		free_str(&g_s->str);
	if (g_s->index > 10)
	{
		g_s->index--;
		tputs(cursor_left, 1, ft_putchar);
		tputs(delete_character, 1, ft_putchar);
		tmp = ft_strldup(g_s->str, ft_strlen(g_s->str) - 1);
		free_str(&g_s->str);
		g_s->str = tmp;
	}
}

void	press_enter(t_read *g_s, int *ex)
{
	int i;

	i = 0;
	if (g_s->str)
		his_add(&g_s->his.his, ft_strdup(g_s->str));
	write(1, "\n", 1);
	proccecing_string(g_s->str, ex, &g_s->his);
	iter(g_s);
}
