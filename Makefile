# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/25 00:45:19 by bbellavi          #+#    #+#              #
#    Updated: 2020/01/25 01:48:43 by bbellavi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -framework OpenGL -framework AppKit
MAKE		= make -C
MLX_DIR		= ./minilibx
NAME		= cub3d
MLX_NAME	= libmlx.a

GRAPH_DIR	= graphics_utils
SRCS		= cub3d.c
SRCS		+= $(GRAPH_DIR)/ft_encode_rgb.c
HEADERS		= headers

all: $(NAME)

$(NAME): $(SRCS)
	# printf "Compiling cub3d\n"
	@$(MAKE) $(MLX_DIR)
	@cp $(MLX_DIR)/libmlx.a .
	@$(CC) -o $(NAME) $(SRCS) $(MLX_NAME) $(CFLAGS) -I $(MLX_DIR) -I $(HEADERS)

clean: fclean

fclean:
	$(MAKE) $(MLX_DIR) clean
	rm -rf $(MLX_NAME)
	rm -rf $(NAME)