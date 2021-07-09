/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:43:09 by drogue            #+#    #+#             */
/*   Updated: 2021/02/16 21:28:44 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	verify_zero(char **pi, int j, int i)
{
	if (!(ft_strchr("210NSEW", pi[i + 1][j + 1])))
		return (-1);
	if (!(ft_strchr("210NSEW", pi[i][j + 1])))
		return (-1);
	if (!(ft_strchr("210NSEW", pi[i - 1][j + 1])))
		return (-1);
	if (!(ft_strchr("210NSEW", pi[i - 1][j])))
		return (-1);
	if (!(ft_strchr("210NSEW", pi[i - 1][j - 1])))
		return (-1);
	if (!(ft_strchr("210NSEW", pi[i][j - 1])))
		return (-1);
	if (!(ft_strchr("210NSEW", pi[i + 1][j - 1])))
		return (-1);
	if (!(ft_strchr("210NSEW", pi[i + 1][j])))
		return (-1);
	return (1);
}

int	verify_zero_player(t_data *data, char **pi, int j, int i)
{
	if (!(ft_strchr("210", pi[i + 1][j + 1])))
		return (-1);
	if (!(ft_strchr("210", pi[i][j + 1])))
		return (-1);
	if (!(ft_strchr("210", pi[i - 1][j + 1])))
		return (-1);
	if (!(ft_strchr("210", pi[i - 1][j])))
		return (-1);
	if (!(ft_strchr("210", pi[i - 1][j - 1])))
		return (-1);
	if (!(ft_strchr("210", pi[i][j - 1])))
		return (-1);
	if (!(ft_strchr("210", pi[i + 1][j - 1])))
		return (-1);
	if (!(ft_strchr("210", pi[i + 1][j])))
		return (-1);
	return (1);
}

int	cheking_value_cell(t_data *data, t_par par, int i, int j)
{
	if (par.map[i][j] == '0')
	{
		if ((verify_zero(par.map, j, i)) == -1)
			return (10);
	}
	if (par.map[i][j] == '2')
	{
		data->count_sprite++;
	}
	if (ft_strchr("NSEW", par.map[i][j]))
	{
		if ((verify_zero_player(data, par.map, j, i)) == -1)
			return (10);
		data->pos.pos_x = j + 0.5;
		data->pos.pos_y = i + 0.5;
		data->count_players++;
	}
	return (0);
}

int	checking_valid_map(t_data *data, t_par par)
{
	int i;
	int j;
	int error;

	i = 0;
	j = 0;
	while (par.map[i] != NULL)
	{
		j = 0;
		while (par.map[i][j])
		{
			if ((error = cheking_value_cell(data, par, i, j)) != 0)
				return (error);
			j++;
		}
		i++;
	}
	return (0);
}
