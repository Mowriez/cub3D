# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 14:55:56 by mtrautne          #+#    #+#              #
#    Updated: 2023/07/27 00:55:48 by mtrautne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLU = \033[34m
RES = \033[0m

CC = gcc
CCFLAG = -Wall -Werror -Wextra 

NAME = cub3D

SRC_NO_DIR = test.c

D_SRC = ./src/
D_OBJ = ./obj/
D_INC = ./inc/

ifeq ($(shell uname), Darwin)
 D_MLX = $(D_INC)mlx/minilibx_opengl_20191021/
 LFLAGS = -L$(D_INC)libft -lft -L$(D_MLX) -framework OpenGL -framework AppKit
else ifeq ($(shell uname), Linux)
D_MLX = $(D_INC)mlx/minilibx-linux/
LFLAGS = -L$(D_INC)libft -lft -L$(D_MLX) -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd
else
 $(error Unsupported operating system: $(shell uname))
endif

MLX = $(D_MLX)libmlx.a
LIBFT = $(D_INC)libft/libft.a

SRC = $(addprefix $(D_SRC), $(SRC_NO_DIR))
OBJ = $(SRC:%.c=%.o)

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

re: fclean all

git:
	git add .
	@echo -n "Enter the commit message: "; \
	read tmp; \
	git commit -m "$$tmp"
	git push
	@echo "$(BLU)'git add .', 'git commit', and 'git push' executed.$(RES)"

.PHONY: all clean fclean re git