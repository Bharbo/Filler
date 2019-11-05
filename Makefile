# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blanna <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/30 13:46:41 by blanna            #+#    #+#              #
#    Updated: 2019/09/30 13:46:43 by blanna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = blanna.filler

SRC = srcs/heat_map.c srcs/main.c srcs/log.c srcs/read_map.c \
srcs/move_player.c srcs/read_token.c srcs/free.c

OBJ = heat_map.o main.o log.o read_map.o \
move_player.o read_token.o free.o

FLAGS = -Wall -Wextra -Werror
LIBRF = libft/libft.a

all: $(NAME)

$(NAME):
		@make re -C libft/ 
		@gcc -c $(SRC)
		@gcc $(LIBRF) $(FLAGS) $(OBJ) -o $(NAME)

clean:
		@make clean -C libft/
		@rm -f $(OBJ)

fclean: clean
		@make fclean -C libft/
		@rm -f $(NAME)

re: fclean all
