/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:18:23 by drogue            #+#    #+#             */
/*   Updated: 2020/12/17 18:10:06 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putnumber_fd(int n, int fd)
{
	if (n > 9 || n < -9)
	{
		putnumber_fd(n / 10, fd);
		putnumber_fd(n % 10, fd);
	}
	else
	{
		if (n < 0)
			n *= -1;
		ft_putchar_fd(n + '0', fd);
	}
}

void	put_hmumber(unsigned int n, int d)
{
	if (n > 15)
	{
		put_hmumber(n / 16, d);
		put_hmumber(n % 16, d);
	}
	else
	{
		if (d == 0)
			ft_putchar_fd("0123456789abcdef"[n], 1);
		if (d == 1)
			ft_putchar_fd("0123456789ABCDEF"[n], 1);
	}
}

void	ft_putnbr_u_fd(unsigned int k, int fd)
{
	if (k > 9)
	{
		putnumber_fd(k / 10, fd);
		putnumber_fd(k % 10, fd);
	}
	else
	{
		ft_putchar_fd(k + '0', fd);
	}
}

void	put_point(unsigned long long n)
{
	if (n > 15)
	{
		put_point(n / 16);
		put_point(n % 16);
	}
	else
	{
		ft_putchar_fd("0123456789abcdef"[n], 1);
	}
}

void	print_value(t_ft_printf par)
{
	if ((char *)par.arg == NULL && par.type == 's')
		write(1, "(null)", par.len_arg);
	par.print_zero == 1 ? write(1, "0", 1) : 0;
	if ((unsigned int)par.arg == 0 && par.have_point && par.type != 'p' &&
												par.type != '%')
		return ;
	if (par.type == 's')
		write(1, (char *)par.arg, par.len_arg);
	par.type == 'd' || par.type == 'i' ? putnumber_fd((int)par.arg, 1) : 0;
	if (par.type == 'p')
	{
		write(1, "0x", 2);
		if (par.have_point != 1 || (char **)par.arg != NULL)
			put_point((unsigned long)par.arg);
	}
	par.type == 'u' ? ft_putnbr_u_fd((unsigned int)par.arg, 1) : 0;
	par.type == 'x' ? put_hmumber((unsigned long)par.arg, 0) : 0;
	par.type == 'X' ? put_hmumber((unsigned int)par.arg, 1) : 0;
	par.type == '%' ? write(1, "%", 1) : 0;
	par.type == 'c' ? ft_putchar_fd((char)par.arg, 1) : 0;
}
