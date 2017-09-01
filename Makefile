# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/15 16:54:06 by dsoloshe          #+#    #+#              #
#    Updated: 2017/06/15 16:54:08 by dsoloshe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = main.c textures.c operations.c operations_part2.c draw_image.c\
	key_hooks.c hooks_part2.c

OBJ = main.o textures.o operations.o operations_part2.o draw_image.o\
	key_hooks.o hooks_part2.o

FLAGS = -Wall -Wextra -Werror

LIBCOMP = cd libft && make && cd ..
LIBCLEAN = cd libft && make clean && cd ..
LIBFCLEAN = cd libft && make fclean && cd ..

MLGCC = gcc -o wolf3d -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	$(LIBCOMP)
	$(LIBCLEAN)
	$(MLGCC) $(FLAGS) $(SRC) libft/libft.a minilibx/libmlx.a

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
