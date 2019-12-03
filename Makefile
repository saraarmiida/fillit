# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spentti <spentti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/25 17:03:51 by spentti           #+#    #+#              #
#    Updated: 2019/11/29 15:29:34 by spentti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS =  -Wall -Wextra -Werror

INCLUDES = fillit.h
FILES = main.c solver.c make_blocks.c get_xy.c create_grid.c validate_file.c

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -I$(INCLUDES) libft/libft.a $(FILES) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

