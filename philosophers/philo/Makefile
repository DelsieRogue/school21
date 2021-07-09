NAME = philo
SRC = exit.c philo_one.c basic_function.c init_arg.c threads.c
OBJ = $(SRC:.c=.o)
RM = rm -f
CC = gcc -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
