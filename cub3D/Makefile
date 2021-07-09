# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drogue <drogue@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 21:34:28 by drogue            #+#    #+#              #
#    Updated: 2021/02/17 16:57:12 by drogue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
LIB = libft/libft.a
SRC = cub_3d.c \
		gnl/get_next_line_utils.c \
		gnl/get_next_line.c \
		file_processing/check_arg_prog.c \
		file_processing/check_side_map.c \
		file_processing/check_valid_map.c \
		file_processing/checking_par.c \
		file_processing/filling_list.c \
		file_processing/reading_file.c \
		file_processing/simple_function_read.c \
		file_processing/my_atoi.c \
		error_processing/error_processing.c \
		zero_initialization/init_mlx_par.c \
		zero_initialization/initialization_position.c \
		zero_initialization/read_sprites.c \
		rendering/background_rendering.c \
		rendering/screenshot.c \
		rendering/main_render/calculation_values.c \
		rendering/main_render/initialization_ren.c \
		rendering/main_render/print_wall.c \
		rendering/render_sprite/print_sprite.c \
		rendering/render_sprite/sprites_processing.c \
		rendering/movement/move.c \
		rendering/movement/rotate.c

OBJ = $(SRC:.c=.o)
RM = rm -f
FLAGS = gcc -Wall -Werror -Wextra -framework OpenGL -framework Appkit -lmlx
OBJL = ./libft $(MAKE)
MLX = ./minilibx_mms_20200219 $(MAKE)

all: $(NAME)

$(NAME): $(OBJ) $(OBJL) $(MLX)
	$(MAKE) -C ./minilibx_mms_20200219
	cp ./minilibx_mms_20200219/libmlx.dylib ./
	$(MAKE) -C ./libft
	$(FLAGS) $(OBJ) $(LIB) libmlx.dylib -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./minilibx_mms_20200219
	$(RM) $(OBJ) $(OBJB)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) libmlx.dylib
	$(RM) $(NAME)
	$(RM) screenshot.bmp

re: fclean all

.PHONY: clean fclean re all
