/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:58:34 by drogue            #+#    #+#             */
/*   Updated: 2020/11/11 19:30:27 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	len_nbr(int n)
{
	int len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	power_ten(int len)
{
	int a;

	a = 1;
	while (--len)
	{
		a *= 10;
	}
	return (a);
}

static void	nbr_str(int a, char *str, int len)
{
	int i;

	i = 0;
	while (len != 0)
	{
		str[i] = a / power_ten(len) + 48;
		a %= power_ten(len);
		i++;
		len--;
	}
}

char		*ft_itoa(int n)
{
	char	*pi;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = len_nbr(n);
	if (n <= 0)
		len++;
	if (!(pi = malloc(sizeof(char) * (len + 1))))
		return (0);
	pi[len] = 0;
	if (n < 0)
	{
		pi[0] = '-';
		nbr_str(-n, ++pi, len - 1);
		return (--pi);
	}
	else
	{
		nbr_str(n, pi, len);
		return (pi);
	}
}
