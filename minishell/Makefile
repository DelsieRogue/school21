NAME = minishell
LIBS = -ltermcap libs/libft.a
CC=gcc
FLAGS = -Wall -Wextra -Werror -std=c99 -g

HEADERS =	libs/gnl/get_next_line.h \
			libs/libft/libft.h \
			headers/minishell.h

SRC =		libs/gnl/get_next_line_utils.c \
			libs/gnl/get_next_line.c \
			srcs/basic_fun_proc.c \
			srcs/basic_func.c \
			srcs/basic_pars_fun.c \
			srcs/call_errors.c \
			srcs/call_execve.c \
			srcs/call_exit.c \
			srcs/call_fun.c \
			srcs/call_pipe.c \
			srcs/call_redirect.c \
			srcs/add_for_cd.c \
			srcs/cd.c \
			srcs/echo.c \
			srcs/add_for_envs.c \
			srcs/add_for_envs2.c \
			srcs/add_for_envs3.c \
			srcs/envs.c \
			srcs/key_control.c \
			srcs/key_history.c \
			srcs/key_move.c \
			srcs/minishell.c \
			srcs/pars_doll.c \
			srcs/pars_quot.c \
			srcs/pars_spec_simvols.c \
			srcs/parser.c \
			srcs/proc_history.c \
			srcs/pwd.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	$(MAKE) -C ./libs/libft
	cp ./libs/libft/libft.a ./libs/.
	$(CC) $(SRC) $(LIBS) $(FLAGS) -o $(NAME)

clean:
	$(MAKE) clean -C ./libs/libft
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libs/libft
	rm -f $(NAME)

re: fclean all

run: all
	./minishell

norm:
	$(MAKE) norm -C ./libs/libft
	norminettev2 $(HEADERS) $(SRC)
