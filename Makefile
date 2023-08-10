# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 14:38:58 by mtrautne          #+#    #+#              #
#    Updated: 2023/08/10 14:39:11 by mtrautne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GRE = \033[32m
BLU = \033[34m
RES = \033[0m

CC = gcc

CCFLAG = -Wall -Werror -Wextra -Ofast


NAME = cub3D

SRC_NO_DIR =	cast_drawer.c \
				cast_drawer_scope.c \
				cast_minimap.c \
				motion_move.c \
				motion.c \
				motion_pan.c \
				cast_raycaster.c \
				deb_utils2.c \
				deb_utils1.c \
				deb_overlay.c \
				error.c \
				init_textures.c \
				init_map_utils1.c \
				init_map_utils2.c \
				init_map.c \
				init_map_identifiers.c \
				init_struct_utils.c \
				init_struct.c \
				init_key_input.c \
				main.c \
				par_error_check.c \
				par_free.c	\
				par_map_identifiers.c \
				par_map_identifiers1.c \
				par_map_valid_utils.c \
				par_map_valid.c \
				par_argv_check.c \
				par_utils.c \
				00_timing.c

D_SRC = ./src/
D_OBJ = ./obj/
D_INC = ./inc/

# choose correct MLX directory depending on the environment OS
ifeq ($(shell uname), Darwin)
 D_MLX = $(D_INC)mlx/minilibx_opengl_20191021/
 LFLAGS = -L$(D_INC)libft -lft -L$(D_MLX) -lmlx -framework OpenGL -framework AppKit -lm
else ifeq ($(shell uname), Linux)
D_MLX = $(D_INC)mlx/minilibx-linux/
LFLAGS = -L$(D_INC)libft -lft -L$(D_MLX) -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd
else
 $(error Unsupported operating system: $(shell uname))
endif

MLX = $(D_MLX)libmlx.a
LIBFT = $(D_INC)libft/libft.a

SRC = $(addprefix $(D_SRC), $(SRC_NO_DIR))
OBJ = $(subst $(D_SRC), $(D_OBJ), $(SRC:.c=.o))

$(D_OBJ)%.o: $(D_SRC)%.c
	@$(CC) $(CCFLAG) -o $@ -c $<
	@echo "$(BLU)$@ built successfully!$(RES)"

all: $(D_OBJ) $(NAME)

$(D_OBJ):
	@mkdir -p $(D_OBJ)
	@echo "$(BLU)$@ created successfully!$(RES)"

$(MLX):
	@make -C $(D_MLX)
	@echo "$(BLU)libmlx.a built successfully!$(RES)"

$(LIBFT):
	@make -C $(D_INC)libft
	@echo "$(BLU)libft built successfully!$(RES)"

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LFLAGS)
	@echo "$(BLU)$@ built successfully!$(RES)"

#-fsanitize=address -static-libasan

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ)
	@rm -rf $(D_OBJ)
	@rm -f $(NAME)
	@make clean -C $(D_MLX)
	@make fclean -C $(D_INC)libft

re: fclean all

git:
	git add .
	@echo -n "Enter the commit message: "; \
	read tmp; \
	git commit -m "$$tmp"
	git push
	@echo "$(GRE)'git add .', 'git commit', and 'git push' executed.$(RES)\n"

.PHONY: all clean fclean re git