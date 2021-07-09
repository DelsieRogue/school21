/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:48:40 by drogue            #+#    #+#             */
/*   Updated: 2021/02/16 21:30:32 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	move_forward(t_data *data)
{
	if (data->par.map[(int)(data->pos.pos_y + data->pos.dir_y * 0.2)]
	[(int)(data->pos.pos_x + data->pos.dir_x * 0.2)] != '1')
	{
		data->pos.pos_x += data->pos.dir_x * 0.1;
		data->pos.pos_y += data->pos.dir_y * 0.1;
	}
}

void	move_back(t_data *data)
{
	if (data->par.map[(int)(data->pos.pos_y - data->pos.dir_y * 0.2)]
	[(int)(data->pos.pos_x - data->pos.dir_x * 0.2)] != '1')
	{
		data->pos.pos_x -= data->pos.dir_x * 0.1;
		data->pos.pos_y -= data->pos.dir_y * 0.1;
	}
}

void	move_left(t_data *data)
{
	if (data->par.map[(int)(data->pos.pos_y - data->pos.dir_x * 0.2)]
	[(int)(data->pos.pos_x + data->pos.dir_y * 0.2)] != '1')
	{
		data->pos.pos_x += data->pos.dir_y * 0.1;
		data->pos.pos_y -= data->pos.dir_x * 0.1;
	}
}

void	move_right(t_data *data)
{
	if (data->par.map[(int)(data->pos.pos_y + data->pos.dir_x * 0.2)]
	[(int)(data->pos.pos_x - data->pos.dir_y * 0.2)] != '1')
	{
		data->pos.pos_x -= data->pos.dir_y * 0.1;
		data->pos.pos_y += data->pos.dir_x * 0.1;
	}
}
