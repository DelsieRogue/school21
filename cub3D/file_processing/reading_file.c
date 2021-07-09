/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:13:39 by drogue            #+#    #+#             */
/*   Updated: 2021/02/16 21:28:51 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	reading_size_map(t_list *file)
{
	int len;

	len = 0;
	while (file->next != NULL && *((char *)file->content) != '\0')
	{
		len++;
		file = file->next;
	}
	if (file->next == NULL)
	{
		if (*(char *)file->content != '\0')
			return (len + 1);
		return (len);
	}
	else
	{
		while (file->next != NULL)
		{
			if (*(char *)file->content != '\0')
				return (-1);
			file = file->next;
		}
		return (len);
	}
}

int	reading_map(t_list *file, t_par *par)
{
	int i;
	int lenght;

	i = 0;
	if ((lenght = reading_size_map(file)) == -1)
		return (10);
	if (!(par->map = malloc(sizeof(char *) * (lenght + 1))))
		return (6);
	par->map[lenght] = NULL;
	while (i < lenght)
	{
		if (!(par->map[i] = ft_strdup(file->content)))
			return (6);
		file = file->next;
		i++;
	}
	return (0);
}

int	filling_parameters(char **s, t_data *data)
{
	skip_space(s);
	if (**s == 'N' && *(*s + 1) == 'O' && *(*s + 2) == ' ')
		return (read_textur(s, &data->par.no));
	if (**s == 'S' && *(*s + 1) == 'O' && *(*s + 2) == ' ')
		return (read_textur(s, &data->par.so));
	if (**s == 'W' && *(*s + 1) == 'E' && *(*s + 2) == ' ')
		return (read_textur(s, &data->par.we));
	if (**s == 'E' && *(*s + 1) == 'A' && *(*s + 2) == ' ')
		return (read_textur(s, &data->par.ea));
	if (**s == 'S' && *(*s + 1) == ' ')
		return (read_textur(s, &data->par.sp));
	if (**s == 'R' && *(*s + 1) == ' ')
		return (read_resolution(s, data));
	if (**s == 'C' && *(*s + 1) == ' ')
		return (reading_colors(s, data->par.cel));
	if (**s == 'F' && *(*s + 1) == ' ')
		return (reading_colors(s, data->par.floor));
	return (7);
}

int	reading_parameters_map(t_data *data)
{
	t_list	*file;
	char	*s;
	int		i;
	int		error;

	i = 0;
	file = data->file;
	while (i < 8)
	{
		s = (char *)data->file->content;
		if ((error = filling_parameters(&s, data)) != 0)
		{
			data->file = file;
			return (error);
		}
		data->file = data->file->next;
		i++;
	}
	if ((error = (reading_map(data->file, &data->par))) != 0)
	{
		data->file = file;
		return (error);
	}
	data->file = file;
	return (0);
}
