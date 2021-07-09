/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:38:35 by drogue            #+#    #+#             */
/*   Updated: 2021/02/16 21:30:36 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

int		exit_game(t_data *data)
{
	exit(0);
}

void	rotate_l(t_data *data)
{
	float old_dir_x;
	float old_plane_x;

	old_dir_x = data->pos.dir_x;
	data->pos.dir_x = data->pos.dir_x * cos(-0.05)
		- data->pos.dir_y * sin(-0.05);
	data->pos.dir_y = old_dir_x * sin(-0.05) +
		data->pos.dir_y * cos(-0.05);
	old_plane_x = data->pos.plane_x;
	data->pos.plane_x = data->pos.plane_x * cos(-0.05)
		- data->pos.plane_y * sin(-0.05);
	data->pos.plane_y = old_plane_x * sin(-0.05)
		+ data->pos.plane_y * cos(-0.05);
}

void	rotate_r(t_data *data)
{
	float old_dir_x;
	float old_plane_x;

	old_dir_x = data->pos.dir_x;
	data->pos.dir_x = data->pos.dir_x * cos(0.05)
		- data->pos.dir_y * sin(0.05);
	data->pos.dir_y = old_dir_x * sin(0.05) +
		data->pos.dir_y * cos(0.05);
	old_plane_x = data->pos.plane_x;
	data->pos.plane_x = data->pos.plane_x * cos(0.05)
		- data->pos.plane_y * sin(0.05);
	data->pos.plane_y = old_plane_x * sin(0.05)
		+ data->pos.plane_y * cos(0.05);
}
