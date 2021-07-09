/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len_par.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:17:24 by drogue            #+#    #+#             */
/*   Updated: 2020/12/17 21:14:42 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_nbr(unsigned int number_u, char a, t_ft_printf *par)
{
	int number_i_d;
	int len;

	len = 0;
	if (a == 'd' || a == 'i')
	{
		number_i_d = (int)number_u;
		if (number_i_d < 0)
			(*par).sign_number = 1;
		while (number_i_d != 0)
		{
			number_i_d /= 10;
			len++;
		}
	}
	else
	{
		while (number_u != 0)
		{
			number_u /= 10;
			len++;
		}
	}
	return (len);
}

int	len_p_nbr(unsigned long long number_p)
{
	int				len;

	len = 2;
	while (number_p != 0)
	{
		number_p /= 16;
		len++;
	}
	return (len);
}

int	len_x_nbr(unsigned int number_x)
{
	int len;

	len = 0;
	while (number_x != 0)
	{
		number_x /= 16;
		len++;
	}
	return (len);
}

int	get_len_argument(char **a, va_list mas, t_ft_printf *par)
{
	char *pi;

	while (**a && (pi = ft_strchr("cspdiuxX%", **a)))
	{
		*pi != '%' ? (*par).arg = va_arg(mas, void *) : 0;
		(*par).type = *pi;
		if (((char**)(*par).arg) == NULL && (*par).type == 'p'
										&& (*par).have_point != 1)
			return (3);
		if ((char *)(*par).arg == NULL && (*par).type == 's')
			return (6);
		if ((((unsigned int)(*par).arg) == 0 && (*par).have_point == 0) ||
												*pi == 'c' || *pi == '%')
			return (1);
		if (*pi == 's')
			return (ft_strlen((char *)(*par).arg));
		if (*pi == 'd' || *pi == 'i' || *pi == 'u')
			return (len_nbr((unsigned int)(*par).arg, *pi, par));
		if (*pi == 'p')
			return (len_p_nbr((unsigned long long)(*par).arg));
		if (*pi == 'x' || *pi == 'X')
			return (len_x_nbr((unsigned int)(*par).arg));
		(*a)++;
	}
	return (-1);
}
