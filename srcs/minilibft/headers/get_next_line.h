/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 03:28:32 by bbellavi          #+#    #+#             */
/*   Updated: 2020/01/26 01:37:27 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H

#	define NEWLINE '\n'
#   define BUFFER_SIZE 64

#	define SUCCESS 1
#	define ERROR -1
#	define END_OF_FILE 0
#	define NOT_FOUND -1
#	define CONTINUE 2

#include "ft_string.h"

#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_string.h"

int		get_next_line(int fd, char **line);

#	endif
