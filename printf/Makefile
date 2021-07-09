# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drogue <drogue@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/06 11:06:20 by drogue            #+#    #+#              #
#    Updated: 2020/12/15 14:36:45 by drogue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIB = libft/libft.a
SRC = ft_printf.c get_len_par.c get_mod.c print_arg.c print_space_zero.c
OBJ = $(SRC:.c=.o)
RM = rm -f
CC = gcc -Wall -Werror -Wextra -c
OBJL = ./libft $(MAKE)

all: $(NAME)

$(NAME): $(OBJ) $(OBJL)
	$(MAKE) -C ./libft
	cp $(LIB) $(NAME)
	ar -rcs $(NAME) $(OBJ)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ) $(OBJB)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
	
re: fclean all

.PHONY: clean fclean re all
