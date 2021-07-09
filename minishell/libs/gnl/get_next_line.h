/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:59:18 by bshawnee          #+#    #+#             */
/*   Updated: 2021/04/08 14:30:53 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFFER_SIZE 100

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*ft_strjoins(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int ch);

int		get_next_line(int fd, char **line);

#endif
