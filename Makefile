# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/30 11:55:01 by plisieck          #+#    #+#              #
#    Updated: 2015/06/09 23:11:27 by plisieck         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = computor
SRC = computor.c computor1.c computor2.c computor3.c computor4.c \
	  computor5.c computor6.c computor7.c computor8.c
OBJ = computor.o computor1.o computor2.o computor3.o computor4.o \
	  computor5.o computor6.o computor7.o computor8.o
FLAGS = -Wall -Wextra -Werror
MLX = -framework OpenGL -framework AppKit -lmlx

all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(SRC)
	@make -C libft
	@gcc -o $(NAME) $(FLAGS) $(OBJ) libft/libft.a $(MLX)
	@echo "\033[33;32mDone !\033[0;0m"

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
