# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/25 00:45:19 by bbellavi          #+#    #+#              #
#    Updated: 2020/05/25 03:40:11 by bbellavi         ###   ########.fr        #
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
PARSE_DIR	= parser

SRCS		= cub3d.c
SRCS		+= $(GRAPH_DIR)/ft_encode_rgb.c
SRCS		+= $(UTILS_DIR)/vectors.c
SRCS		+= $(UTILS_DIR)/rotate.c
SRCS		+= $(UTILS_DIR)/angle.c
SRCS		+= $(UTILS_DIR)/is_wall.c
SRCS		+= $(UTILS_DIR)/utils1.c
SRCS		+= $(GAME_DIR)/render.c
SRCS		+= $(GAME_DIR)/loop.c
SRCS		+= $(GAME_DIR)/image.c
SRCS		+= $(GAME_DIR)/rays.c
SRCS		+= $(GAME_DIR)/minimap.c
SRCS		+= $(GAME_DIR)/movements.c
SRCS		+= $(GAME_DIR)/raycasting.c
SRCS		+= $(HOOK_DIR)/keyboard_hooks.c
SRCS		+= $(PARSE_DIR)/parser.c
SRCS		+= $(PARSE_DIR)/parse_utils_1.c
SRCS		+= $(PARSE_DIR)/parse_utils_2.c
SRCS		+= $(PARSE_DIR)/parse_utils_3.c
SRCS		+= $(PARSE_DIR)/parse_utils_4.c
SRCS		+= $(PARSE_DIR)/errors.c
SRCS		+= $(PARSE_DIR)/map_processor.c
SRCS		+= $(PARSE_DIR)/color_parser.c
SRCS		+= $(PARSE_DIR)/texture_parser.c
SRCS		+= $(PARSE_DIR)/resolution_parser.c
HEADERS		= headers
LFT_HEADERS	= $(LFT_DIR)/headers

all: $(NAME)

$(NAME): $(SRCS)
	@$(MAKE) $(MLX_DIR)
	@$(MAKE) $(LFT_DIR)
	@cp $(MLX_DIR)/$(MLX_NAME) .
	@cp $(LFT_DIR)/$(LFT_NAME) .
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
