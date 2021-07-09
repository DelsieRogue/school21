/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:16:51 by drogue            #+#    #+#             */
/*   Updated: 2021/02/16 13:09:58 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	par_init(t_data *data)
{
	data->sprites = NULL;
	data->sprite_order = NULL;
	data->sprite_dis = NULL;
	data->count_sprite = 0;
	data->file = NULL;
	data->par.no = NULL;
	data->par.so = NULL;
	data->par.we = NULL;
	data->par.ea = NULL;
	data->par.sp = NULL;
	data->par.width = -1;
	data->par.height = -1;
	data->par.cel[0] = -1;
	data->par.cel[1] = -1;
	data->par.cel[2] = -1;
	data->par.floor[0] = -1;
	data->par.floor[1] = -1;
	data->par.floor[2] = -1;
}

int		file_processing(t_data *data, int argc, char **argv)
{
	int		error;

	if ((error = check_arguments(data, argc, argv)) != 0)
		return (error);
	if ((error = filling_list(&data->file, data)) != 0)
		return (error);
	if ((error = reading_parameters_map(data)) != 0)
		return (error);
	if ((error = checking_parameters(data)) != 0)
		return (error);
	if ((error = checking_side_map(data->par)) != 0)
		return (error);
	if ((error = checking_valid_map(data, data->par)) != 0)
		return (error);
	if (data->count_players != 1)
		return (11);
	return (0);
}

void	main_rendering(t_data *data, t_pos *pos)
{
	int i;

	i = 0;
	pos->buffer = malloc(sizeof(float) * data->par.width);
	background_rendering(data);
	while (i < data->par.width)
	{
		initialization_ren(data, pos, i);
		calculate_param(pos, data);
		print_wall(&data->pos, data, i);
		pos->buffer[(int)i] = pos->perp_wall_dist;
		i++;
	}
	sprites_processing(data, pos);
	if (data->save == 1)
	{
		if (screenshot(data) == -1)
			error_processing(12, data);
	}
	free(pos->buffer);
	pos->buffer = NULL;
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
}

int		reading_key(int key, t_data *data)
{
	if (key == 53)
		exit(0);
	if (key == 123)
		rotate_l(data);
	if (key == 124)
		rotate_r(data);
	if (key == 13)
		move_forward(data);
	if (key == 1)
		move_back(data);
	if (key == 0)
		move_left(data);
	if (key == 2)
		move_right(data);
	main_rendering(data, &data->pos);
	return (0);
}

int		main(int argc, char **argv)
{
	t_data	data;
	int		error;

	par_init(&data);
	if ((error = (file_processing(&data, argc, argv))) != 0)
		error_processing(error, &data);
	initialization_pos(&data);
	if ((init_mlx(&data.mlx, data)) != 0)
		error_processing(error, &data);
	read_sprites(&data, data.par);
	main_rendering(&data, &data.pos);
	mlx_hook(data.mlx.win, 2, 1L << 0, reading_key, &data);
	mlx_hook(data.mlx.win, 17, 1L << 2, exit_game, &data);
	mlx_loop(data.mlx.mlx);
	return (0);
}
