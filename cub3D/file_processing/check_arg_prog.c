/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_prog.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 18:37:42 by drogue            #+#    #+#             */
/*   Updated: 2021/02/16 21:28:38 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	check_file(t_data *data, char *str)
{
	int i;

	if ((i = ft_strlen(str) - 4) < 0)
		return (2);
	if ((ft_strncmp(str + i, ".cub", 4)) != 0)
		return (2);
	data->fd = open(str, O_RDONLY);
	if (data->fd == -1)
		return (3);
	return (0);
}

int	check_arguments(t_data *data, int argc, char **argv)
{
	int error;

	error = 0;
	if (argc == 2 || argc == 3)
	{
		data->save = 0;
		if (((error = check_file(data, argv[1])) != 0))
			return (error);
		if (argc == 3)
		{
			data->save = 1;
			if (ft_strlen(argv[2]) != 6 ||
								ft_strncmp(argv[2], "--save", 6) != 0)
				return (4);
		}
	}
	else
		return (1);
	return (error);
}
