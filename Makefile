# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 15:55:47 by jsteuber          #+#    #+#              #
#    Updated: 2019/05/29 17:36:20 by jsteuber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS += -Wall -Wextra -Werror

SRC = main.c image.c actions.c actions2.c \
mandelbrot.c julia.c burning_ship.c start.c \
parser.c palettes.c colors.c

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/
LIBFT_A = libft.a
LIBFT_L	= -L ./libft -l ft

MLX = ./minilibx_macos/
MLX_A = libmlx.a
MLX_L = -L ./minilibx_macos -l mlx -framework OpenGL -framework AppKit

.PHONY = all clean fclean re

all: $(LIBFT_A) $(MLX_A) $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

$(LIBFT_A):
	@make -C $(LIBFT)

$(MLX_A):
	@make -C $(MLX)

$(NAME): $(OBJ)
	gcc $(OBJ) $(LIBFT_L) $(MLX_L) -lm -o $(NAME)


clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT) clean
	@make -C $(MLX) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all
