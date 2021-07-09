/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:16:23 by drogue            #+#    #+#             */
/*   Updated: 2020/12/16 10:52:22 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		getting_first_modifiers(char **a)
{
	int first_par;

	first_par = 0;
	while (**a == '-' || **a == '0')
	{
		if (**a == '-')
			first_par = 1;
		if (**a == '0' && first_par != 1)
			first_par = 2;
		(*a)++;
	}
	return (first_par);
}

int		getting_width_modifiers(char **a, va_list mas)
{
	int width;

	width = 0;
	while (**a >= '0' && **a <= '9')
	{
		width = 10 * width + **a - '0';
		(*a)++;
	}
	if (**a == '*')
	{
		width = va_arg(mas, int);
		(*a)++;
	}
	return (width);
}

int		getting_width_par_modifiers(char **a, va_list mas, t_ft_printf *par)
{
	int width;

	width = 0;
	if (**a == '.')
	{
		(*a)++;
		(*par).have_point = 1;
		if ((**a >= '0' && **a <= '9') || **a == '-')
		{
			width = ft_atoi(*a);
			while ((**a >= '0' && **a <= '9') || **a == '-')
				(*a)++;
		}
		if (**a == '*')
		{
			width = va_arg(mas, int);
			(*a)++;
		}
		return (width);
	}
	return (0);
}
