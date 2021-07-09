/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:31:41 by drogue            #+#    #+#             */
/*   Updated: 2021/02/17 02:44:17 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_lstsize(t_list *lst);
int					ft_isascii(int c);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					my_atoi(const char *str);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
