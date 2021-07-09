/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:49:26 by drogue            #+#    #+#             */
/*   Updated: 2021/02/17 17:06:50 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		full_free(char **line, char **res, char **buf);
int		ft_strlen2(char *s);
char	*ft_strdup2(char *s1, char **res);
char	*ft_strchr2(char *s, int c);
char	*ft_strjoin2(char *s1, char *s2, char **s3);
int		check_buffer(char **buf, char **line, char **res);
int		buffer_parse(char **buf, char **line, char **res, int fd);
int		check_res(char **line, char **res);

#endif
