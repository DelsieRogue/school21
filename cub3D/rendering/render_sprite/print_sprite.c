/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:12:04 by drogue            #+#    #+#             */
/*   Updated: 2021/02/16 21:30:42 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	draw_column(char *addr, char *addr_img, t_data *data)
{
	int i;
	int kf;

	i = data->pos.draw_start_y;
	if (data->pos.transform_y > 0 && data->pos.draw_start_x > 0
	&& data->pos.draw_start_x < data->par.width &&
	data->pos.transform_y < data->pos.buffer[data->pos.draw_start_x])
	{
		while (i < data->pos.draw_end_y)
		{
			kf = i * 256 - data->par.height * 128
				+ data->pos.sprite_height * 128;
			data->pos.tex_y = ((kf * 64) / data->pos.sprite_height) / 256;
			if (*(unsigned int*)(addr_img +
				data->pos.tex_y * data->mlx.spr.ll) != 0)
			{
				*(unsigned int*)(addr + i * data->mlx.ll) =
				*(unsigned int*)(addr_img + data->pos.tex_y * data->mlx.spr.ll);
			}
			i++;
		}
	}
}

void	print_sprites(t_pos *pos, t_data *data)
{
	char *addr;
	char *addr_img;

	while (pos->draw_start_x < pos->draw_end_x)
	{
		pos->tex_x = (int)(256 * (pos->draw_start_x - (-pos->sprite_width / 2
				+ pos->sprite_screen_x)) * 64 / pos->sprite_width) / 256;
		addr_img = data->mlx.spr.addr + pos->tex_x * (data->mlx.spr.bp / 8);
		addr = data->mlx.addr + pos->draw_start_x * (data->mlx.bp / 8);
		draw_column(addr, addr_img, data);
		pos->draw_start_x++;
	}
}
