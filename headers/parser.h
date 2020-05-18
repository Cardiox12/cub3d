/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 02:01:35 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/18 22:28:15 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef FT_PARSER_H
#   define FT_PARSER_H

#include <fcntl.h>
#include "types.h"
#include "graphics_utils.h"
#include "ft_string.h"
#include "ft_stdio.h"

# define MAP_EXT ".cub"

typedef struct	s_id
{
	char		*id;
	int			index;
}				t_id;

int		parse(t_game *data, const char *path);
// Define callbacks
void	parse_texture(t_game *data, const char *id);
void	parse_color(t_game *data, const char *id);
void	parse_resolution(t_game *data, const char *id);

# define ID_SIZE 8
# define CALLBACKS_SIZE 3


enum	callback_index
{
	COLOR_INDEX,
	RESOLUTION_INDEX,
	TEXTURE_INDEX
};

static t_id ids[ID_SIZE] = {
	{"NO", TEXTURE_INDEX},
	{"SO", TEXTURE_INDEX},
	{"EA", TEXTURE_INDEX},
	{"WE", TEXTURE_INDEX},
	{"S", TEXTURE_INDEX},
	{"R", RESOLUTION_INDEX},
	{"F", COLOR_INDEX},
	{"C", COLOR_INDEX}
};

static void (*parse_callbacks[CALLBACKS_SIZE])(t_game*, const char*) = {
	parse_color,
	parse_resolution,
	parse_texture
};

# define ERROR -1

#   endif
