/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_ren.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 20:07:11 by drogue            #+#    #+#             */
/*   Updated: 2021/02/16 21:30:17 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	initialization_step(t_pos *pos)
{
	if (pos->ray_dir_x < 0)
	{
		pos->step_x = -1;
		pos->side_dist_x = (pos->pos_x - pos->map_x) * pos->delta_dist_x;
	}
	else
	{
		pos->step_x = 1;
		pos->side_dist_x = (pos->map_x + 1 - pos->pos_x) * pos->delta_dist_x;
	}
	if (pos->ray_dir_y < 0)
	{
		pos->step_y = -1;
		pos->side_dist_y = (pos->pos_y - pos->map_y) * pos->delta_dist_y;
	}
	else
	{
		pos->step_y = 1;
		pos->side_dist_y = (pos->map_y + 1 - pos->pos_y) * pos->delta_dist_y;
	}
}

void	initialization_ren(t_data *data, t_pos *pos, int i)
{
	pos->hit = 0;
	pos->camera_x = 2 * i / (float)data->par.width - 1;
	pos->ray_dir_x = pos->dir_x + pos->plane_x * pos->camera_x;
	pos->ray_dir_y = pos->dir_y + pos->plane_y * pos->camera_x;
	pos->map_x = (int)pos->pos_x;
	pos->map_y = (int)pos->pos_y;
	pos->delta_dist_x = fabs(1 / pos->ray_dir_x);
	pos->delta_dist_y = fabs(1 / pos->ray_dir_y);
	initialization_step(pos);
}
