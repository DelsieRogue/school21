/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:13:17 by drogue            #+#    #+#             */
/*   Updated: 2021/02/17 06:17:05 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_header(t_data *data, t_header *header)
{
	header->size_file = 54 + 4 * data->par.height * data->par.width;
	header->reserved = 0;
	header->pixel_offset = 54;
	header->size_header = 40;
	header->width = data->par.width;
	header->height = -data->par.height;
	header->number_planes = 1;
	header->color_depth = 32;
	header->compression = 0;
	header->raw_size = 0;
	header->horizontal_res = 3780;
	header->vertical_res = 3780;
	header->color_entries = 0;
	header->important_col = 0;
}

int		write_img(int fd, t_data *data, t_mlx mlx)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < data->par.height)
	{
		j = 0;
		while (j < data->par.width)
		{
			if (write(fd, (unsigned int *)(mlx.addr +
				i * mlx.ll + j * (mlx.bp / 8)), 4) != 4)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int		filling_header(int fd, t_header header)
{
	int a;

	a = 0;
	a += write(fd, "BM", 2);
	a += write(fd, &header.size_file, 4);
	a += write(fd, &header.reserved, 4);
	a += write(fd, &header.pixel_offset, 4);
	a += write(fd, &header.size_header, 4);
	a += write(fd, &header.width, 4);
	a += write(fd, &header.height, 4);
	a += write(fd, &header.number_planes, 2);
	a += write(fd, &header.color_depth, 2);
	a += write(fd, &header.compression, 4);
	a += write(fd, &header.raw_size, 4);
	a += write(fd, &header.horizontal_res, 4);
	a += write(fd, &header.vertical_res, 4);
	a += write(fd, &header.color_entries, 4);
	a += write(fd, &header.important_col, 4);
	if (a != 54)
		return (-1);
	return (0);
}

int		screenshot(t_data *data)
{
	int				fd;
	t_header		header;

	if (!(fd = open("screenshot.bmp", O_CREAT | O_RDWR, S_IRWXU)))
		return (-1);
	init_header(data, &header);
	if (filling_header(fd, header) == -1)
		return (-1);
	if (write_img(fd, data, data->mlx) == -1)
		return (-1);
	data->save = 0;
	close(fd);
	return (0);
}
