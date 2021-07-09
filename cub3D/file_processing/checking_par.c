/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_par.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:40:25 by drogue            #+#    #+#             */
/*   Updated: 2021/02/16 21:28:47 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	checking_parameters(t_data *data)
{
	int i;
	int width;
	int height;

	i = 0;
	mlx_get_screen_size(data->mlx.mlx, &width, &height);
	if (data->par.no == NULL || data->par.so == NULL || data->par.we == NULL ||
	data->par.ea == NULL || data->par.sp == NULL)
		return (8);
	while (i < 3)
	{
		if (data->par.cel[i] < 0 || data->par.cel[i] > 255)
			return (7);
		if (data->par.floor[i] < 0 || data->par.floor[i] > 255)
			return (7);
		i++;
	}
	if (data->par.width <= 0 || data->par.height <= 0)
		return (7);
	data->par.width = (data->par.width > width) ? width : data->par.width;
	data->par.height = (data->par.height > height) ? height : data->par.height;
	return (0);
}
