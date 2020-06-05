# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/25 00:45:19 by bbellavi          #+#    #+#              #
#    Updated: 2020/06/05 14:47:18 by bbellavi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOR_NC			= \e[0m
COLOR_LIGHT_GREEN	= \e[1;32m
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -lm
MAKE		= make -C
MLX_DIR		= minilibx
NAME		= cub3d
MLX_NAME	= libmlx.a
LFT_NAME	= libftmini.a

SRCS_DIR	= srcs
GRAPH_DIR	= $(SRCS_DIR)/graphics_utils
UTILS_DIR	= $(SRCS_DIR)/utils
GAME_DIR	= $(SRCS_DIR)/game
HOOK_DIR	= $(SRCS_DIR)/event_hooks
LFT_DIR		= $(SRCS_DIR)/minilibft
PARSE_DIR	= $(SRCS_DIR)/parser
BMP_DIR		= $(SRCS_DIR)/export
VEC_DIR		= $(SRCS_DIR)/vectors

HEADERS		= headers
HEADERS_SRC = $(HEADERS)/bitmap.h\
$(HEADERS)/cub3d.h\
$(HEADERS)/errors.h\
$(HEADERS)/event_hooks.h\
$(HEADERS)/graphics_utils.h\
$(HEADERS)/parser.h\
$(HEADERS)/render.h\
$(HEADERS)/types.h\
$(HEADERS)/utils.h\
$(HEADERS)/vectors.h


SRCS		= cub3d.c
SRCS		+= $(GRAPH_DIR)/ft_encode_rgb.c
SRCS		+= $(UTILS_DIR)/angle.c
SRCS		+= $(UTILS_DIR)/is_wall.c
SRCS		+= $(UTILS_DIR)/utils1.c
SRCS		+= $(UTILS_DIR)/sort.c
SRCS		+= $(UTILS_DIR)/free_game.c
SRCS		+= $(GAME_DIR)/init_1.c
SRCS		+= $(GAME_DIR)/render.c
SRCS		+= $(GAME_DIR)/loop.c
SRCS		+= $(GAME_DIR)/image.c
SRCS		+= $(GAME_DIR)/rays.c
SRCS		+= $(GAME_DIR)/minimap.c
SRCS		+= $(GAME_DIR)/movements.c
SRCS		+= $(GAME_DIR)/raycasting.c
SRCS		+= $(HOOK_DIR)/event_hooks.c
SRCS		+= $(VEC_DIR)/vec_rotate.c
SRCS		+= $(VEC_DIR)/vec_add.c
SRCS		+= $(VEC_DIR)/vec_cast.c
SRCS		+= $(VEC_DIR)/vec_dist.c
SRCS		+= $(VEC_DIR)/vec_div.c
SRCS		+= $(VEC_DIR)/vec_dot.c
SRCS		+= $(VEC_DIR)/vec_get_angle.c
SRCS		+= $(VEC_DIR)/vec_mag.c
SRCS		+= $(VEC_DIR)/vec_mult.c
SRCS		+= $(VEC_DIR)/vec_neg.c
SRCS		+= $(VEC_DIR)/vec_norm.c
SRCS		+= $(PARSE_DIR)/parser.c
SRCS		+= $(PARSE_DIR)/sprites_parser.c
SRCS		+= $(PARSE_DIR)/parse_utils_1.c
SRCS		+= $(PARSE_DIR)/parse_utils_2.c
SRCS		+= $(PARSE_DIR)/parse_utils_3.c
SRCS		+= $(PARSE_DIR)/parse_utils_4.c
SRCS		+= $(PARSE_DIR)/errors.c
SRCS		+= $(PARSE_DIR)/map_processor.c
SRCS		+= $(PARSE_DIR)/color_parser.c
SRCS		+= $(PARSE_DIR)/texture_parser.c
SRCS		+= $(PARSE_DIR)/resolution_parser.c
SRCS		+= $(PARSE_DIR)/cmd_parser.c
SRCS		+= $(BMP_DIR)/export.c
LFT_HEADERS	= $(LFT_DIR)/headers

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS_SRC)
	@$(MAKE) $(MLX_DIR)
	@$(MAKE) $(LFT_DIR)
	@cp $(MLX_DIR)/$(MLX_NAME) .
	@cp $(LFT_DIR)/$(LFT_NAME) .
	@printf "$(COLOR_LIGHT_GREEN)COMPILING CUB3D$(COLOR_NC)\n"
	@$(CC) -g -o $(NAME) $(SRCS) $(CFLAGS) -I $(MLX_DIR) -I $(HEADERS) -I $(LFT_HEADERS) -lmlx -L. -lftmini -L. -lXext -lX11

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
