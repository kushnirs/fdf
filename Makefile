# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/09 11:17:10 by skushnir          #+#    #+#              #
#    Updated: 2018/01/09 11:34:51 by skushnir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =  fdf.c read_coordinate.c ft_keys.c action.c draw_line.c

HDR = fdf.h minilibx/mlx.h

LIB = libft/libft.a minilibx/libmlx.a

OBJ = $(SRC:.c=.o)

all: $(SRC) $(SRC_PR) $(NAME)

$(NAME): $(OBJ) $(HDR) $(LIB)
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) $(LIB) -framework OpenGl -framework AppKit

.c.o:
	@gcc  -Wall -Wextra -Werror -c $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all