/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_side_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:42:10 by drogue            #+#    #+#             */
/*   Updated: 2021/02/16 21:28:41 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	check_top_bottom(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j] != '\0')
	{
		if (map[i][j] != ' ' && map[i][j] != '1')
			return (10);
		j++;
	}
	return (0);
}

int	checking_side_map(t_par par)
{
	int i;

	i = 0;
	if ((check_top_bottom(par.map, 0)) != 0)
		return (10);
	while (par.map[i] != NULL)
	{
		if (par.map[i][0] != ' ' && par.map[i][0] != '1')
			return (10);
		if (par.map[i][ft_strlen(par.map[i]) - 1] != '1' &&
		par.map[i][ft_strlen(par.map[i]) - 1] != ' ')
			return (10);
		i++;
	}
	if ((check_top_bottom(par.map, --i)) != 0)
		return (10);
	return (0);
}
