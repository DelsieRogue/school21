/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_processing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:33:46 by drogue            #+#    #+#             */
/*   Updated: 2021/02/16 21:30:50 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	sp_order_dis(t_data *data, t_pos *pos)
{
	int i;

	i = 0;
	data->sprite_order = malloc(sizeof(int) * data->count_sprite);
	data->sprite_dis = malloc(sizeof(float) * data->count_sprite);
	while (i < data->count_sprite)
	{
		data->sprite_order[i] = i;
		data->sprite_dis[i] = ((pos->pos_x - data->sprites[i].x)
		* (pos->pos_x - data->sprites[i].x) + (pos->pos_y - data->sprites[i].y)
		* (pos->pos_y - data->sprites[i].y));
		i++;
	}
}

void	sort_sprites(t_data *data, t_pos *pos)
{
	int tmp;
	int i;

	i = 0;
	sp_order_dis(data, pos);
	while (i + 1 < data->count_sprite)
	{
		if (data->sprite_dis[data->sprite_order[i]] <
				data->sprite_dis[data->sprite_order[i + 1]])
		{
			tmp = data->sprite_order[i];
			data->sprite_order[i] = data->sprite_order[i + 1];
			data->sprite_order[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	calculate_drow_sp(t_data *data, t_pos *pos)
{
	pos->draw_start_y = -pos->sprite_height / 2 +
					data->par.height / 2 + pos->v_move_screen;
	if (pos->draw_start_y < 0)
		pos->draw_start_y = 0;
	pos->draw_end_y = pos->sprite_height / 2 +
					data->par.height / 2 + pos->v_move_screen;
	if (pos->draw_end_y >= data->par.height)
		pos->draw_end_y = data->par.height - 1;
	pos->sprite_width = abs((int)(data->par.height
						/ (pos->transform_y))) / 1;
	pos->draw_start_x = -pos->sprite_width / 2 +
					pos->sprite_screen_x + pos->v_move_screen;
	if (pos->draw_start_x < 0)
		pos->draw_start_x = 0;
	pos->draw_end_x = pos->sprite_width / 2 +
					pos->sprite_screen_x + pos->v_move_screen;
	if (pos->draw_end_x >= data->par.width)
		pos->draw_end_x = data->par.width - 1;
}

void	calculate_par_sp(t_data *data, t_pos *pos, int i)
{
	pos->sprite_x = data->sprites[(int)data->sprite_order[i]].x - pos->pos_x;
	pos->sprite_y = data->sprites[(int)data->sprite_order[i]].y - pos->pos_y;
	pos->inv_det = 1.00 / (pos->plane_x * pos->dir_y - pos->plane_y
															* pos->dir_x);
	pos->transform_x = pos->inv_det * (pos->dir_y * pos->sprite_x
											- pos->dir_x * pos->sprite_y);
	pos->transform_y = pos->inv_det * (-pos->plane_y * pos->sprite_x
											+ pos->plane_x * pos->sprite_y);
	pos->sprite_screen_x = (int)((data->par.width / 2)
								* (1 + pos->transform_x / pos->transform_y));
	pos->v_move_screen = (int)(0.0 / pos->transform_y);
	pos->sprite_height = abs((int)(data->par.height / (pos->transform_y))) / 1;
}

void	sprites_processing(t_data *data, t_pos *pos)
{
	int i;

	i = 0;
	sort_sprites(data, pos);
	while (i < data->count_sprite)
	{
		calculate_par_sp(data, pos, i);
		calculate_drow_sp(data, pos);
		print_sprites(&data->pos, data);
		i++;
	}
	free(data->sprite_order);
	data->sprite_order = NULL;
	free(data->sprite_dis);
	data->sprite_dis = NULL;
}
