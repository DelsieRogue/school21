/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:14:08 by drogue            #+#    #+#             */
/*   Updated: 2021/05/27 18:15:27 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	iter(t_read *g_s)
{
	free_str(&g_s->str);
	g_s->i = 0;
	g_s->index = write(1, "bash-1.0$ ", 10);
	tputs(save_cursor, 1, ft_putchar);
	free_str(&g_s->his.tmp_his);
	g_s->his.i_his = ft_strlen_mas(g_s->his.his);
	g_s->his.check = 0;
}

int		check_simvol(t_read *g_s, char *buf, int *ex)
{
	int a;

	a = 1;
	if (!(ft_strcmp(buf, "\e[A")) && a--)
		press_up(g_s, &g_s->his);
	else if (!(ft_strcmp(buf, "\e[B")) && a--)
		press_down(g_s, &g_s->his);
	else if (!(ft_strcmp(buf, "\x7f")) && a--)
		press_backspace(g_s);
	else if (!(ft_strcmp(buf, "\e[D")) && a--)
		press_left(g_s);
	else if (!(ft_strcmp(buf, "\e[C")) && a--)
		press_right(g_s);
	else if (!(ft_strcmp(buf, "\n")) && a--)
		press_enter(g_s, ex);
	else if (!(ft_strcmp(buf, "\t")) && a--)
		return (0);
	if (a > 0)
		return (1);
	return (0);
}

int		check_signal(t_read *g_s, char *buf, int *ex)
{
	if (!ft_strcmp(buf, "\4"))
	{
		if (g_s->str)
			return (0);
		set_history(&g_s->his);
		write(1, "exit\n", 5);
		exit(*ex);
	}
	else if (!ft_strcmp(buf, "\3"))
	{
		write(1, "\n", 1);
		iter(g_s);
		return (0);
	}
	else if (buf[0] == '\x1c')
		return (0);
	return (1);
}

int		main(void)
{
	t_read	g_s;
	char	buf[2000];
	int		ex;

	ex = 0;
	g_s.str = NULL;
	g_s.his.tmp_his = NULL;
	get_history(&g_s.his);
	get_list_env();
	term_on();
	iter(&g_s);
	while (1)
	{
		term_on();
		ft_bzero(buf, 2000);
		read(0, buf, 200);
		term_off();
		if (check_simvol(&g_s, buf, &ex) && check_signal(&g_s, buf, &ex))
		{
			g_s.index += write(1, buf, ft_strlen(buf));
			add_str(&g_s.str, buf);
		}
	}
	return (0);
}
