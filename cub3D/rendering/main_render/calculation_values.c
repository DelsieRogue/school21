/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:24:22 by drogue            #+#    #+#             */
/*   Updated: 2021/02/16 21:30:15 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	calculate_param(t_pos *pos, t_data *data)
{
	search_border(pos, data);
	if (pos->side == 0)
		pos->perp_wall_dist = (pos->map_x - pos->pos_x +
					(1 - pos->step_x) / 2) / pos->ray_dir_x;
	else
		pos->perp_wall_dist = (pos->map_y - pos->pos_y +
					(1 - pos->step_y) / 2) / pos->ray_dir_y;
	pos->line_height = (int)(data->par.height / pos->perp_wall_dist);
	pos->draw_start = data->par.height / 2 - pos->line_height / 2;
	if (pos->draw_start < 0)
		pos->draw_start = 0;
	pos->draw_end = data->par.height / 2 + pos->line_height / 2;
	if (pos->draw_end >= data->par.height)
		pos->draw_end = data->par.height;
	if (pos->side == 0)
		pos->wall_x = pos->pos_y + pos->perp_wall_dist * pos->ray_dir_y;
	else
		pos->wall_x = pos->pos_x + pos->perp_wall_dist * pos->ray_dir_x;
	pos->wall_x -= floor(pos->wall_x);
	pos->tex_x = (int)(pos->wall_x * 64.00);
	if (pos->side == 0 && pos->ray_dir_x > 0)
		pos->tex_x = 64 - pos->tex_x - 1;
	if (pos->side == 1 && pos->ray_dir_y < 0)
		pos->tex_x = 64 - pos->tex_x - 1;
	pos->step = 64.00 / pos->line_height;
}

void	search_border(t_pos *pos, t_data *data)
{
	while (pos->hit == 0)
	{
		if (pos->side_dist_x < pos->side_dist_y)
		{
			pos->side_dist_x += pos->delta_dist_x;
			pos->map_x += pos->step_x;
			pos->side = 0;
			data->nwse = (pos->step_x > 0) ? 0 : 1;
		}
		else
		{
			pos->side_dist_y += pos->delta_dist_y;
			pos->map_y += pos->step_y;
			pos->side = 1;
			data->nwse = (pos->step_y > 0) ? 2 : 3;
		}
		if (data->par.map[pos->map_y][pos->map_x] == '1')
			pos->hit = 1;
	}
}
