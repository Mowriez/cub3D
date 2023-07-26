# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 14:55:56 by mtrautne          #+#    #+#              #
#    Updated: 2023/07/26 21:53:41 by mtrautne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLU = \033[34m
RES = \033[0m

CC = cc
CCFLAG = -Wall -Werror -Wextra

NAME = cub3D

SRC_NO_DIR = test.c

D_SRC = ./src/
D_OBJ = ./obj/
D_INC = ./inc/

ifeq ($(shell uname), Linux)
 D_MLX = $(D_INC)/mlx/minilibx_linux/
else ifeq ($(shell uname), Darwin)
 D_MLX = $(D_INC)/mlx/minilibx_opengl_20191021/
else
 $(error Unsupported operating system: $(shell uname))
endif

MLX = $(D_MLX)libmlx.a
LIBFT = $(D_INC)libft/libft.a
LIBS = -L$(D_INC)libft -L$(D_MLX) -lft -lmlx -lm -framework OpenGL -framework AppKit

SRC = $(addprefix $(D_SRC), $(SRC_NO_DIR))
OBJ = $(subst $(D_SRC), $(D_OBJ), $(SRC:.c=.o))

all: $(D_OBJ) $(NAME)

$(D_OBJ):
	@mkdir -p $(D_OBJ)
	@echo "$(BLU)$@ created successfully!$(RES)"

$(D_OBJ)%.o: $(D_SRC)%.c
	@$(CC) $(CCFLAG) -I$(D_INC) -I$(D_MLX) -o $@ -c $<
	@echo "$(BLU)$@ built successfully!$(RES)"

$(MLX):
	@make -C $(D_MLX)
	@echo "$(BLU)libmlx.a built successfully!$(RES)"

$(LIBFT):
	@make -C $(D_INC)libft
	@echo "$(BLU)libft built successfully!$(RES)"

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	@$(CC) $(CCFLAG) $(LIBS) $(OBJ) -o $(NAME)
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
	@echo "$(BLU)$git add ., commit, and push executed.$(RES)"

.PHONY: all clean fclean re git