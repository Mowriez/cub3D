# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 14:55:56 by mtrautne          #+#    #+#              #
#    Updated: 2023/08/04 08:33:47 by mtrautne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GRE = \033[32m
BLU = \033[34m
RES = \033[0m

CC = gcc
CCFLAG = -Wall -Werror -Wextra -O3 -g

NAME = cub3D

SRC_NO_DIR =	cast_drawer.c \
				cast_raycaster.c \
				deb_dtoa.c \
				deb_helpers.c \
				deb_minimap.c \
				deb_overlay.c \
				error.c \
				init_helpers.c \
				init_map.c \
				init_struct.c \
				key_input_helpers.c \
				key_input.c \
				main.c \
				par_parser.c \
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

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ)
	@rm -rf $(D_OBJ)
	@rm -f $(NAME)
	@make clean -C $(D_MLX)
	@make fclean -C $(D_INC)libft

# !doesnt recompile MLX/LIBFT, for faster compilation during project development.
re:
	@rm -f $(OBJ)
	@rm -rf $(D_OBJ)
	@rm -f $(NAME)
	make all

# !actual rule for re, replace before handing in project
re_deep: fclean all

# !prompts for a commit message, then pushes to remote repository. remove before handing in project
git:
	git add .
	@echo -n "Enter the commit message: "; \
	read tmp; \
	git commit -m "$$tmp"
	git push
	@echo "$(GRE)'git add .', 'git commit', and 'git push' executed.$(RES)\n"

.PHONY: all clean fclean re re_deep git