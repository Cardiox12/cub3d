# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/25 00:45:19 by bbellavi          #+#    #+#              #
#    Updated: 2020/02/19 15:37:48 by bbellavi         ###   ########.fr        #
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
LFT_NAME	= libftmini.a

GRAPH_DIR	= graphics_utils
UTILS_DIR	= utils
GAME_DIR	= game
HOOK_DIR	= event_hooks
LFT_DIR		= minilibft
SRCS		= cub3d.c
SRCS		+= $(GRAPH_DIR)/ft_encode_rgb.c
SRCS		+= $(GRAPH_DIR)/ft_line.c
SRCS		+= $(GRAPH_DIR)/ft_rect.c
SRCS		+= $(UTILS_DIR)/init_mlx_infos.c
SRCS		+= $(UTILS_DIR)/init_textures.c
SRCS		+= $(UTILS_DIR)/init_vec.c
SRCS		+= $(UTILS_DIR)/init_map.c
SRCS		+= $(UTILS_DIR)/parse_map.c
SRCS		+= $(GAME_DIR)/game.c
SRCS		+= $(HOOK_DIR)/keyboard_hooks.c
HEADERS		= headers
LFT_HEADERS	= $(LFT_DIR)/headers

all: $(NAME)

$(NAME): $(SRCS)
	@$(MAKE) $(MLX_DIR)
	@$(MAKE) $(LFT_DIR)
	@cp $(MLX_DIR)/libmlx.a .
	@cp $(LFT_DIR)/libftmini.a .
	clear
	@printf "$(COLOR_LIGHT_GREEN)COMPILING CUB3D$(COLOR_NC)\n"
	@$(CC) -g -o $(NAME) $(SRCS) $(LFT_NAME) $(MLX_NAME) $(CFLAGS) -I $(MLX_DIR) -I $(HEADERS) -I $(LFT_HEADERS)

clean: fclean

fclean:
	@printf "$(COLOR_LIGHT_GREEN)REMOVING FILES$(COLOR_NC)\n"
	@$(MAKE) $(MLX_DIR) clean
	@$(MAKE) $(LFT_DIR) fclean
	@rm -rf $(MLX_NAME)
	@rm -rf $(LFT_NAME)
	@rm -rf $(NAME)
	@rm -rf cub3d.dSYM

re: fclean $(NAME)