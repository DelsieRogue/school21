/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:39:58 by drogue            #+#    #+#             */
/*   Updated: 2021/02/16 21:29:34 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	putstr_error(char *s)
{
	write(1, s, ft_strlen(s));
}

void	error_processing(int i, t_data *data)
{
	if (i == 1)
		putstr_error("Error\nWrong number of arguments\n");
	if (i == 2)
		putstr_error("Error\nInvalid file permission (.cub)\n");
	if (i == 3)
		putstr_error("Error\nFile not found\n");
	if (i == 4)
		putstr_error("Error\nSecond argument is incorrectly specified\n");
	if (i == 5)
		putstr_error("Error\nError reading file, please try again\n");
	if (i == 6)
		putstr_error("Error\nFailed to allocate memory\n");
	if (i == 7 || i == 8)
		putstr_error("Error\nInvalid game parameters specified\n");
	if (i == 9)
		putstr_error("Error\nImage not found\n");
	if (i == 10)
		putstr_error("Error\nNot a valid map\n");
	if (i == 11)
		putstr_error("Error\nInvalid number of players\n");
	if (i == 12)
		putstr_error("Error\nScreenshot creation error\n");
	exit(0);
}
