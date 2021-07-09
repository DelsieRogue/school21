/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 20:02:17 by drogue            #+#    #+#             */
/*   Updated: 2021/02/16 21:31:26 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	read_sprites(t_data *data, t_par par)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	data->sprites = malloc(sizeof(t_sprite) * data->count_sprite);
	while (par.map[i] != NULL)
	{
		j = 0;
		while (par.map[i][j])
		{
			if (par.map[i][j] == '2')
			{
				data->sprites[k].x = j + 0.5;
				data->sprites[k].y = i + 0.5;
				k++;
			}
			j++;
		}
		i++;
	}
	return (0);
}
