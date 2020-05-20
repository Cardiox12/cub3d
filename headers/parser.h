/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 02:01:35 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/20 22:08:16 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef FT_PARSER_H
#   define FT_PARSER_H

#include <fcntl.h>
#include "types.h"
#include "graphics_utils.h"
#include "ft_string.h"
#include "ft_stdio.h"
#include "ft_ctypes.h"
#include "ft_std.h"

typedef struct	s_id
{
	char		*id;
	int			index;
}				t_id;

int		parse(t_game *data, const char *path);

int		parse_texture(t_game *data, const char *id, char *line);
int		parse_color(t_game *data, const char *id, char *line);
int		parse_resolution(t_game *data, const char *id, char *line);

char	*skip_spaces(const char *s);
char	*skip_char(const char *s, unsigned char c);
char	*skip_digits(const char *s);
int		has_valid_ext(const char *path);
int		max(int a, int b);
void	freeline(t_game *data);
int		is_mapline(const char *line);

# define ID_SIZE 8
# define RGB_SIZE 3
# define CALLBACKS_SIZE 3


enum	callback_index
{
	COLOR_INDEX,
	RESOLUTION_INDEX,
	TEXTURE_INDEX
};

# define ID_NORTH	"NO"
# define ID_SOUTH	"SO"
# define ID_EAST	"EA"
# define ID_WEST	"WE"
# define ID_SPRITE	"S"
# define ID_RES		"R"
# define ID_CEIL	"C"
# define ID_FLOOR	"F"

static t_id ids[ID_SIZE] = {
	{ID_NORTH, TEXTURE_INDEX},
	{ID_SOUTH, TEXTURE_INDEX},
	{ID_EAST, TEXTURE_INDEX},
	{ID_WEST, TEXTURE_INDEX},
	{ID_SPRITE, TEXTURE_INDEX},
	{ID_RES, RESOLUTION_INDEX},
	{ID_FLOOR, COLOR_INDEX},
	{ID_CEIL, COLOR_INDEX}
};

static int (*parse_callbacks[CALLBACKS_SIZE])(t_game*, const char*, char*) = {
	parse_color,
	parse_resolution,
	parse_texture
};

# define ERROR -1
# define SUCCESS 1
# define MAP_EXT ".cub"

// Charset definition
# define COMMA ','
# define SPACE ' '
# define MAP_CHARSET "012NSEW"

#endif
