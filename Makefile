# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/25 00:45:19 by bbellavi          #+#    #+#              #
#    Updated: 2020/01/26 03:11:13 by bbellavi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOR_NC			= \e[0m
COLOR_LIGHT_GREEN	= \e[1;32m
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -framework OpenGL -framework AppKit
MAKE		= make -C
MLX_DIR		= ./minilibx
NAME		= cub3d
MLX_NAME	= libmlx.a

GRAPH_DIR	= graphics_utils
UTILS_DIR	= utils
HOOK_DIR	= event_hooks
SRCS		= cub3d.c
SRCS		+= $(GRAPH_DIR)/ft_encode_rgb.c
SRCS		+= $(GRAPH_DIR)/ft_line.c
SRCS		+= $(UTILS_DIR)/init_mlx_infos.c
SRCS		+= $(UTILS_DIR)/init_textures.c
SRCS		+= $(UTILS_DIR)/init_vec.c
SRCS		+= $(UTILS_DIR)/init_map.c
SRCS		+= $(HOOK_DIR)/keyboard_hooks.c
HEADERS		= headers

all: $(NAME)

$(NAME): $(SRCS)
	@$(MAKE) $(MLX_DIR)
	@cp $(MLX_DIR)/libmlx.a .
	clear
	@printf "$(COLOR_LIGHT_GREEN)COMPILING CUB3D$(COLOR_NC)\n"
	@$(CC) -o $(NAME) $(SRCS) $(MLX_NAME) $(CFLAGS) -I $(MLX_DIR) -I $(HEADERS)

clean: fclean

fclean:
	@printf "$(COLOR_LIGHT_GREEN)REMOVING FILES$(COLOR_NC)\n"
	@$(MAKE) $(MLX_DIR) clean
	@rm -rf $(MLX_NAME)
	@rm -rf $(NAME)

re: fclean $(NAME)