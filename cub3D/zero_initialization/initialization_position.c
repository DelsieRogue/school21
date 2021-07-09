/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_position.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:46:46 by drogue            #+#    #+#             */
/*   Updated: 2021/02/16 21:31:20 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_n(t_data *data)
{
	data->pos.dir_x = 0;
	data->pos.dir_y = -1;
	data->pos.plane_x = 0.66;
	data->pos.plane_y = 0;
}

void	init_s(t_data *data)
{
	data->pos.dir_x = 0;
	data->pos.dir_y = 1;
	data->pos.plane_x = -0.66;
	data->pos.plane_y = 0;
}

void	init_e(t_data *data)
{
	data->pos.dir_x = 1;
	data->pos.dir_y = 0;
	data->pos.plane_x = 0;
	data->pos.plane_y = 0.66;
}

void	init_w(t_data *data)
{
	data->pos.dir_x = -1;
	data->pos.dir_y = 0;
	data->pos.plane_x = 0;
	data->pos.plane_y = -0.66;
}

void	initialization_pos(t_data *data)
{
	char c;

	c = data->par.map[(int)data->pos.pos_y][(int)data->pos.pos_x];
	if (c == 'N')
		init_n(data);
	if (c == 'S')
		init_s(data);
	if (c == 'E')
		init_e(data);
	if (c == 'W')
		init_w(data);
}
