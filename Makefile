# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/05 12:04:26 by wphokomp          #+#    #+#              #
#    Updated: 2017/07/09 16:36:16 by wphokomp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Filler

SRC = main.c play.c make_move.c

OBJ = *.o

FLAGS = -Wall -Werror -Wextra -o

all: $(NAME)

$(NAME):
		make -C lib/ fclean && make -C lib/
		clang $(FLAGS) $(NAME) $(SRC) lib/libft.a

clean:
		make -C lib/ clean
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
