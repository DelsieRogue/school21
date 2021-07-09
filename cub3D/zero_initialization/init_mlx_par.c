/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_par.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:54:28 by drogue            #+#    #+#             */
/*   Updated: 2021/02/16 21:31:16 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	create_mxl(t_mlx *mlx, t_data data)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, data.par.width,
		data.par.height, "cub3D");
	mlx->img = mlx_new_image(mlx->mlx, data.par.width,
		data.par.height);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bp,
		&mlx->ll, &mlx->en);
}

void	get_addr_img(t_mlx *mlx)
{
	mlx->tex[0].addr = mlx_get_data_addr(mlx->tex[0].img,
			&mlx->tex[0].bp, &mlx->tex[0].ll, &mlx->tex[0].en);
	mlx->tex[1].addr = mlx_get_data_addr(mlx->tex[1].img,
			&mlx->tex[1].bp, &mlx->tex[1].ll, &mlx->tex[1].en);
	mlx->tex[2].addr = mlx_get_data_addr(mlx->tex[2].img,
			&mlx->tex[2].bp, &mlx->tex[2].ll, &mlx->tex[2].en);
	mlx->tex[3].addr = mlx_get_data_addr(mlx->tex[3].img,
			&mlx->tex[3].bp, &mlx->tex[3].ll, &mlx->tex[3].en);
	mlx->spr.addr = mlx_get_data_addr(mlx->spr.img,
			&mlx->spr.bp, &mlx->spr.ll, &mlx->spr.en);
}

int		init_mlx(t_mlx *mlx, t_data data)
{
	int size;

	create_mxl(mlx, data);
	if ((mlx->tex[0].img = mlx_xpm_file_to_image(mlx->mlx,
						data.par.ea, &size, &size)) == 0)
		return (-1);
	if ((mlx->tex[1].img = mlx_xpm_file_to_image(mlx->mlx,
						data.par.we, &size, &size)) == 0)
		return (-1);
	if ((mlx->tex[2].img = mlx_xpm_file_to_image(mlx->mlx,
						data.par.so, &size, &size)) == 0)
		return (-1);
	if ((mlx->tex[3].img = mlx_xpm_file_to_image(mlx->mlx,
						data.par.no, &size, &size)) == 0)
		return (-1);
	if ((mlx->spr.img = mlx_xpm_file_to_image(mlx->mlx,
						data.par.sp, &size, &size)) == 0)
		return (-1);
	get_addr_img(mlx);
	return (0);
}
