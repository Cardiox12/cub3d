# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/26 01:37:41 by bbellavi          #+#    #+#              #
#    Updated: 2020/05/20 23:38:44 by bbellavi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
NAME		= libftmini.a
CFLAGS		= -Wall -Werror -Wextra -g

INCLUDES	= headers
INC_FILES	= $(INCLUDES)/ft_stdio.h $(INCLUDES)/ft_string.h $(INCLUDES)/get_next_line.h

BASE_DIR	= srcs
STDIO_DIR	= $(BASE_DIR)/stdio
STRING_DIR	= $(BASE_DIR)/string
STD_DIR		= $(BASE_DIR)/std
CTYPES_DIR	= $(BASE_DIR)/ctypes

SRCS	= $(STDIO_DIR)/ft_putchar.c
SRCS	+= $(STDIO_DIR)/ft_putstr.c
SRCS	+= $(STDIO_DIR)/ft_putnbr.c
SRCS	+= $(STDIO_DIR)/get_next_line.c
SRCS	+= $(STRING_DIR)/ft_strjoin.c
SRCS	+= $(STRING_DIR)/ft_strlen.c
SRCS	+= $(STRING_DIR)/ft_strlen_to_sep.c
SRCS	+= $(STRING_DIR)/ft_strdup.c
SRCS	+= $(STRING_DIR)/ft_realloc.c
SRCS	+= $(STRING_DIR)/ft_strndup.c
SRCS	+= $(STRING_DIR)/ft_strncmp.c
SRCS	+= $(STRING_DIR)/ft_split.c
SRCS	+= $(STRING_DIR)/ft_strchr.c
SRCS	+= $(STRING_DIR)/ft_memcpy.c
SRCS	+= $(STRING_DIR)/ft_strtrim.c
SRCS	+= $(STRING_DIR)/ft_memset.c
SRCS	+= $(STD_DIR)/ft_atoi.c
SRCS	+= $(CTYPES_DIR)/ft_isalnum.c
SRCS	+= $(CTYPES_DIR)/ft_isalpha.c
SRCS	+= $(CTYPES_DIR)/ft_isascii.c
SRCS	+= $(CTYPES_DIR)/ft_isdigit.c
SRCS	+= $(CTYPES_DIR)/ft_isprint.c
SRCS	+= $(CTYPES_DIR)/ft_isspace.c

OBJS	= $(SRCS:.c=.o)
.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJS) $(INC_FILES)
	ar -rcs $@ $?

%.o: %.c $(INC_FILES)
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INCLUDES)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all