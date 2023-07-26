# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 22:16:23 by mtrautne          #+#    #+#              #
#    Updated: 2022/12/15 19:22:38 by mtrautne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Naming convention in a Recipes in a Makefile: A RECIPE consists of
#a target: its dependencies
#[Tab] actions that make dependencies into the taget.

#Name of the final executable, in this case the archive/library.
NAME = libft.a

#Not just a Variable but also the compiler thats used by the implicid SRC to\
OBJ compilation. 
CC = gcc

#Flags used for every compilation if not specified otherwise.
CFLAGS = -Wall -Wextra -Werror

#Sourcefiles for the first and second part of the project.
SRCA = ft_calloc.c ft_isdigit.c ft_memcpy.c ft_strdup.c ft_strncmp.c  \
ft_toupper.c ft_isalnum.c ft_isprint.c ft_memmove.c ft_strlcat.c ft_strnstr.c \
ft_atoi.c ft_isalpha.c ft_memchr.c ft_memset.c ft_strlcpy.c ft_strrchr.c \
ft_bzero.c ft_isascii.c ft_memcmp.c ft_strchr.c ft_strlen.c ft_tolower.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
get_next_line_bonus.c get_next_line_utils_bonus.c

#Sourcefiles for the bonus part of the project.
#SRCB = 

#Compiles object-files for the first part oft the project. \
The $(SRC...)-part is an pattern rule, which is a type of implicit rule.\
It compiles the SRC files to object files with the compiler deposited in CC\
and the CFLAGS. It also adds the flags -c (compile without linking) and -o\
(write build output to output file, so .o file has same name as corresponding\
 .c file). Also works with wildcard % (%.c=%.o). 
OBJA = $(SRCA:.c=.o)

#implicit rule for compiling .c to .o, so basically the OBJA-compilation\
above. Makes it possible to insert @ (suppress echo in terminal for\
better comprehension).
%.o: %.c
	@$(CC) $(CFLAGS) -c $(SRCA)
	
#OBJB = Bonus-Objects

#all: by convention builds the final executable/in this case the archive
all: $(NAME)

#Actual recipe to build the Archive. ar is used to link the .o-files\
together, -r is used to replace earlier files with the same name,\
-c is used to create the lib if it didnt exist, without issuing a warning\
 and -s is used to build or update an sorted index of the files in the library \
 file. ar -t "libname" to see the modules inside the library.
$(NAME): $(OBJA) libft.h
	@ar -rcs $(NAME) $(OBJA) 


# clean/fclean are targets without any dependencies, but they have actions.\
-f forces removal but doesnt print out errors if it cant find a file.\
use clean to rm the object files, and fclean to rm the executable and\
the object files.

#by convention clean just removes executables.
clean:	
	@rm -f $(OBJA)

#by convention fclean removes executables and object files, leaves just \
source files.
fclean: clean
	@rm -f $(NAME)

#by convention re is used to fclean and remake the binary/executable.
re: fclean all

#special built in target name to mark targets as "phony". makes the targets\
defined in it run everytime when explicitely requested, even if there is by\
chance a file with the targets name. (Think if a file named clean would\
exist in the directory, then "make clean" would never work, as "clean" has\
no prerequisits/dependencies and so the file "clean" would always be\
considered up to date. 
.PHONY: all clean fclean re