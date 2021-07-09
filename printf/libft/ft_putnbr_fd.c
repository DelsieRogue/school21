/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:02:19 by drogue            #+#    #+#             */
/*   Updated: 2020/11/06 13:29:32 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	k;
	char	c;

	k = (long)n;
	if (k < 0)
	{
		write(fd, "-", 1);
		k *= -1;
	}
	c = k + '0';
	if (k > 9)
	{
		ft_putnbr_fd(k / 10, fd);
		ft_putnbr_fd(k % 10, fd);
	}
	else
	{
		ft_putchar_fd(c, fd);
	}
}
