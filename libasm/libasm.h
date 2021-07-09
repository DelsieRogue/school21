/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 22:36:56 by drogue            #+#    #+#             */
/*   Updated: 2021/03/03 00:40:41 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
#define LIBASM_H

char	*ft_strdup(char *s); // !!! работает, но не проверил выделение памяти
char	*ft_strcpy(char *dest, const char *src); //!!!
int		ft_strlen(char *s); //!!!
int 	ft_strcmp(char *s, char *s2); //!!!
int		ft_write(int fd, char *s, int l);
int		ft_read(int fd, char *buf, int l);

#endif
