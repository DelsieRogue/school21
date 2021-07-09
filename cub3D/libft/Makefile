# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drogue <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/06 11:06:20 by drogue            #+#    #+#              #
#    Updated: 2021/02/16 22:17:20 by drogue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_strlen.c ft_strchr.c ft_strdup.c ft_strncmp.c ft_isascii.c ft_lstsize.c ft_lstadd_back.c
OBJ = $(SRC:.c=.o)
RM = rm -f
CC = gcc -Wall -Werror -Wextra -c

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ) $(OBJB)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
