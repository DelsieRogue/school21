/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:24:54 by drogue            #+#    #+#             */
/*   Updated: 2021/05/23 16:27:48 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	free_str(char **s)
{
	if (s && *s)
	{
		free(*s);
		*s = NULL;
	}
}

int		ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int		add_str(char **str2, char *str)
{
	char *s;

	if (!*str2)
		*str2 = ft_strdup(str);
	else
	{
		s = malloc(ft_strlen(*str2) + ft_strlen(str) + 1);
		ft_memcpy(s, *str2, ft_strlen(*str2));
		ft_memcpy(s + ft_strlen(*str2), str, ft_strlen(str));
		s[ft_strlen(*str2) + ft_strlen(str)] = '\0';
		free_str(str2);
		*str2 = s;
	}
	return (0);
}

int		term_on(void)
{
	struct termios term;

	tgetent(0, "xterm-256color");
	tcgetattr(0, &term);
	term.c_lflag &= ~(ISIG);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &term);
	return (0);
}

int		term_off(void)
{
	struct termios term;

	tcgetattr(0, &term);
	term.c_lflag |= ISIG;
	term.c_lflag |= ECHO;
	term.c_lflag |= ICANON;
	tcsetattr(0, TCSANOW, &term);
	return (0);
}
