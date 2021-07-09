/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:05:01 by drogue            #+#    #+#             */
/*   Updated: 2020/12/17 21:18:29 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero_initialization(t_ft_printf *par)
{
	(*par).arg = 0;
	(*par).sign_number = 0;
	(*par).len_arg = 0;
	(*par).width_all = 0;
	(*par).width_point = 0;
	(*par).type = 0;
	(*par).first_par = 0;
	(*par).have_point = 0;
	(*par).print_zero = 0;
}

void	par_modification(t_ft_printf *par)
{
	if ((*par).have_point == 0)
		(*par).width_point = (*par).len_arg;
	if ((*par).have_point == 1)
	{
		if ((*par).type == '%')
			(*par).width_point = 0;
		if ((*par).width_point < 0 && (int)(*par).arg == 0 &&
								(int)(*par).type != 'p' && (*par).type != 's')
		{
			(*par).print_zero = 1;
			(*par).len_arg = 1;
		}
		if ((*par).first_par == 2 && (*par).width_point >= 0 &&
								(*par).type != 's' && (*par).type != '%')
			(*par).first_par = 0;
		if ((*par).width_point < 0)
			(*par).width_point = (*par).len_arg;
		if ((*par).len_arg < (*par).width_point && (*par).type == 's')
			(*par).width_point = (*par).len_arg;
		if ((*par).len_arg > (*par).width_point && (*par).type == 's')
			(*par).len_arg = (*par).width_point;
		if ((*par).len_arg > (*par).width_point && (*par).type != 's')
			(*par).width_point = (*par).len_arg;
	}
}

int		getting_all_par(char **a, va_list mas, t_ft_printf *par)
{
	(*par).first_par = getting_first_modifiers(a);
	(*par).width_all = getting_width_modifiers(a, mas);
	if ((*par).width_all < 0)
	{
		(*par).width_all *= -1;
		(*par).first_par = 1;
	}
	(*par).width_point = getting_width_par_modifiers(a, mas, par);
	if (((*par).len_arg = get_len_argument(a, mas, par)) == -1)
		return (-1);
	par_modification(par);
	return (print_argument(par));
}

int		parser_str(char *a, va_list mas, t_ft_printf *par)
{
	int ret;
	int tmp;

	ret = 0;
	while (*a != '\0')
	{
		if (*a == '%')
		{
			a++;
			zero_initialization(par);
			if ((tmp = getting_all_par(&a, mas, par)) == -1)
				return (0);
			ret += tmp;
			a++;
		}
		else
		{
			write(1, a, 1);
			a++;
			ret++;
		}
	}
	return (ret);
}

int		ft_printf(const char *a, ...)
{
	char		*s;
	va_list		mas;
	t_ft_printf	par;
	int			ret;

	s = (char *)a;
	va_start(mas, a);
	ret = parser_str(s, mas, &par);
	va_end(mas);
	return (ret);
}
