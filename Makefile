# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 14:55:56 by mtrautne          #+#    #+#              #
#    Updated: 2023/07/26 21:47:37 by mtrautne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


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
	@echo "\033[34m$@ created successfully!\033[0m"

$(D_OBJ)%.o: $(D_SRC)%.c
	@$(CC) $(CCFLAG) -I$(D_INC) -I$(D_MLX) -o $@ -c $<
	@echo "\033[34m$@ built successfully!\033[0m"

$(MLX):
	@make -C $(D_MLX)
	@echo "\033[34mlibmlx.a built successfully!\033[0m"

$(LIBFT):
	@make -C $(D_INC)libft
	@echo "\033[34mlibft built successfully!\033[0m"

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	@$(CC) $(CCFLAG) $(LIBS) $(OBJ) -o $(NAME)
	@echo "\033[34m$@ built successfully!\033[0m"

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ)
	@rm -rf $(D_OBJ)
	@rm -f $(NAME)
	@make clean -C $(D_MLX)

re : fclean all

git:
	git add .
	@echo -n "Enter the commit message: "; \
	read tmp; \
	git commit -m "$$tmp"
	git push
	@echo "\033[34mgit add ., commit with message '$$tmp', and push executed.\033[0m"

.PHONY: all clean fclean re