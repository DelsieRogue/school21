/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:49:26 by drogue            #+#    #+#             */
/*   Updated: 2020/11/25 04:19:43 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		full_free(char **line, char **res, char **buf);
int		ft_strlen(char *s);
char	*ft_strdup(char *s1, char **res);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2, char **s3);
int		check_buffer(char **buf, char **line, char **res);
int		buffer_parse(char **buf, char **line, char **res, int fd);
int		check_res(char **line, char **res);

#endif
