/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:29:07 by drogue            #+#    #+#             */
/*   Updated: 2021/02/16 21:30:20 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	print_wall(t_pos *pos, t_data *data, int i)
{
	int		kf;
	char	*addr;
	char	*addr_img;

	addr = data->mlx.addr + i * (data->mlx.bp / 8);
	addr_img = data->mlx.tex[data->nwse].addr +
		(63 - pos->tex_x) * (data->mlx.tex[data->nwse].bp / 8);
	while (pos->draw_start < pos->draw_end)
	{
		kf = (pos->draw_start - data->par.height / 2 +
					pos->line_height / 2) * pos->step;
		*(unsigned int*)(addr + pos->draw_start * data->mlx.ll) =
			*(unsigned int*)(addr_img + kf * data->mlx.tex[data->nwse].ll);
		pos->draw_start++;
	}
}
