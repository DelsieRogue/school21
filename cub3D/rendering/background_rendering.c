/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_rendering.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:26:38 by drogue            #+#    #+#             */
/*   Updated: 2021/02/16 21:30:57 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx.addr + (y * data->mlx.ll + x * (data->mlx.bp / 8));
	*(unsigned int*)dst = color;
}

int		background_rendering(t_data *data)
{
	int i;
	int j;
	int *c1;
	int *c2;

	i = 0;
	j = 0;
	c1 = data->par.cel;
	c2 = data->par.floor;
	while (i < data->par.height)
	{
		j = 0;
		while (j < data->par.width)
		{
			if (i < data->par.height / 2)
				my_mlx_pixel_put(data, j, i, (c1[0] << 16) |
					(c1[1] << 8) | (c1[2] << 0));
			else
				my_mlx_pixel_put(data, j, i, (c2[0] << 16) |
					(c2[1] << 8) | (c2[2] << 0));
			j++;
		}
		i++;
	}
	return (0);
}
