# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sergee <sergee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/09 11:17:10 by skushnir          #+#    #+#              #
#    Updated: 2018/01/13 03:21:54 by sergee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =  fdf.c utility.c draw_polygon.c

HDR = fdf.h minilibx/mlx.h

LIB = libft/libft.a minilibx/libmlx.a

OBJ = $(SRC:.c=.o)

all: $(SRC) $(SRC_PR) $(NAME)

$(NAME): $(OBJ) $(HDR) $(LIB)
	gcc -Wall -Wextra -Werror -O3 -o $(NAME) $(OBJ) $(LIB) -framework OpenGl -framework AppKit

.c.o:
	@gcc  -Wall -Wextra -Werror  -O3 -c $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all