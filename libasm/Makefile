# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drogue <drogue@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 21:34:28 by drogue            #+#    #+#              #
#    Updated: 2021/03/03 03:35:52 by drogue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
TEST = test
SRC = ft_read.s ft_strcmp.s ft_strcpy.s ft_strdup.s ft_strlen.s ft_write.s
SRC_T = main.c
OBJ = $(SRC:.s=.o)
RM = rm -f
FLAGS = -f macho64

%.o: %.s
	nasm $(FLAGS) $<

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $^

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(TEST) test.txt

test: $(NAME)
	gcc $(SRC_T) $(NAME) -o $(TEST)

re: fclean all
