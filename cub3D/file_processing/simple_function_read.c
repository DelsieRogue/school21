/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_function_read.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:17:09 by drogue            #+#    #+#             */
/*   Updated: 2021/02/16 22:28:19 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	skip_space(char **s)
{
	while (**s == ' ' || **s == '\t')
		(*s)++;
}

int		read_textur(char **s, char **textur)
{
	*s = *s + 2;
	skip_space(s);
	if (!(*textur = ft_strdup(*s)))
		return (6);
	if (open(*textur, O_RDONLY) == -1)
		return (9);
	return (0);
}

int		read_resolution(char **s, t_data *data)
{
	*s = *s + 1;
	skip_space(s);
	data->par.width = my_atoi(*s);
	while ((**s >= '0' && **s <= '9'))
		(*s)++;
	if (**s != ' ' && **s != '\t')
		return (7);
	data->par.height = my_atoi(*s);
	skip_space(s);
	while ((**s >= '0' && **s <= '9'))
		(*s)++;
	skip_space(s);
	if (**s != '\0')
		return (7);
	return (0);
}

int		check_comma(char **s)
{
	while ((**s >= '0' && **s <= '9'))
		(*s)++;
	if (**s == ',')
	{
		(*s)++;
		if (**s >= '0' && **s <= '9')
			return (1);
	}
	return (-1);
}

int		reading_colors(char **s, int *color)
{
	*s = *s + 1;
	skip_space(s);
	color[0] = my_atoi(*s);
	if (check_comma(s) == -1)
		return (7);
	color[1] = my_atoi(*s);
	if (check_comma(s) == -1)
		return (7);
	color[2] = my_atoi(*s);
	while ((**s >= '0' && **s <= '9'))
		(*s)++;
	skip_space(s);
	if (**s == '\0')
		return (0);
	return (7);
}
