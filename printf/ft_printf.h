/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 13:37:05 by drogue            #+#    #+#             */
/*   Updated: 2020/12/16 10:48:51 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct		s_ft_printf
{
	void			*arg;
	int				len_arg;
	int				first_par;
	int				width_all;
	int				width_point;
	int				sign_number;
	char			type;
	int				have_point;
	int				print_zero;
}					t_ft_printf;

void				zero_initialization(t_ft_printf *par);
int					getting_first_modifiers(char **a);
int					getting_width_modifiers(char **a, va_list mas);
int					getting_width_par_modifiers(char **a, va_list mas,
														t_ft_printf *par);
int					len_nbr(unsigned int number_u, char a, t_ft_printf *par);
int					len_h_nbr(unsigned long long number_p, char type);
int					get_len_argument(char **a, va_list mas, t_ft_printf *par);
void				putnumber_fd(int n, int fd);
void				put_hmumber(unsigned int n, int d);
void				ft_putnbr_u_fd(unsigned int k, int fd);
void				put_point(unsigned long long n);
void				par_modification(t_ft_printf *par);
void				print_value(t_ft_printf par);
int					printf_left(t_ft_printf *par);
int					printf_right(t_ft_printf *par, char a);
int					print_argument(t_ft_printf *par);
int					getting_all_par(char **a, va_list mas, t_ft_printf *par);
int					ft_printf(const char *a, ...);

#endif
