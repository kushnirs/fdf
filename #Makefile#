# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sergee <sergee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/09 11:17:10 by skushnir          #+#    #+#              #
#    Updated: 2018/01/15 01:02:53 by sergee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =  fdf.c utility.c draw_polygon.c z_buff.c

HDR = fdf.h

LIB = libft/libft.a minilibx/libmlx.a

OBJ = $(SRC:.c=.o)

all:lib $(NAME)

$(NAME): $(OBJ) $(HDR) $(LIB)
	gcc -Wall -Wextra -Werror -O3 -o $(NAME) $(OBJ) $(LIB) -framework OpenGl -framework AppKit

.c.o:
	gcc  -Wall -Wextra -Werror  -O3 -c $<

lib: 
	make -C libft;
clean:
	@make -C libft clean;
	@rm -f $(OBJ)

fclean: clean
	@make -C libft fclean;
	@rm -f $(NAME)

re: fclean all

.NOTPARALLEL: all $(NAME) re