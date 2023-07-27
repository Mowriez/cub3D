# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 14:55:56 by mtrautne          #+#    #+#              #
#    Updated: 2023/07/28 00:50:47 by mtrautne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLU = \033[34m
RES = \033[0m

CC = gcc
CCFLAG = -Wall -Werror -Wextra -O3 #-g

NAME = cub3D

SRC_NO_DIR =	error.c \
				init_init.c \
				init_utils.c \
				main.c \
				par_parser.c \
				par_utils.c \
				\
				vis_visualizer.c

D_SRC = ./src/
D_OBJ = ./obj/
D_INC = ./inc/

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

re: fclean all

git:
	git add .
	@echo -n "Enter the commit message: "; \
	read tmp; \
	git commit -m "$$tmp"
	git push
	@echo "$(BLU)'git add .', 'git commit', and 'git push' executed.$(RES)"

.PHONY: all clean fclean re git