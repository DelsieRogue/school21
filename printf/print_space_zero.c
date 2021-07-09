/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_space_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:19:31 by drogue            #+#    #+#             */
/*   Updated: 2020/12/16 10:20:11 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_left(t_ft_printf *par)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	if ((*par).sign_number == 1)
	{
		ret += write(1, "-", 1);
		(*par).width_all--;
	}
	while ((*par).width_point - i > (*par).len_arg)
	{
		ret += write(1, "0", 1);
		i++;
	}
	print_value(*par);
	i = 0;
	while ((*par).width_all - i > (*par).width_point)
	{
		ret += write(1, " ", 1);
		i++;
	}
	return (ret + (*par).len_arg);
}

int		printf_right(t_ft_printf *par, char a)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	if ((*par).sign_number == 1)
		(*par).width_all--;
	if (a == '0' && (*par).sign_number == 1)
		ret += write(1, "-", 1);
	while ((*par).width_all - i > (*par).width_point)
	{
		ret += write(1, &a, 1);
		i++;
	}
	if ((*par).sign_number == 1 && a != '0')
		ret += write(1, "-", 1);
	i = 0;
	while ((*par).width_point - i > (*par).len_arg)
	{
		ret += write(1, "0", 1);
		i++;
	}
	print_value(*par);
	return (ret + (*par).len_arg);
}

int		print_argument(t_ft_printf *par)
{
	if ((*par).first_par == 1)
		return (printf_left(par));
	else if ((*par).first_par == 0)
		return (printf_right(par, ' '));
	else if ((*par).first_par == 2)
		return (printf_right(par, '0'));
	return (0);
}
