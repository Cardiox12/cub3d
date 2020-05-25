/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 02:01:35 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/25 06:55:53 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef FT_PARSER_H
#   define FT_PARSER_H

#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include "types.h"
#include "graphics_utils.h"
#include "ft_string.h"
#include "ft_stdio.h"
#include "ft_ctypes.h"
#include "ft_std.h"

typedef struct	s_id
{
	char			*id;
	int				index;
	unsigned int	flag;
}				t_id;

typedef struct	s_stack
{
	struct s_stack	*next;
	t_vec			pos;
}				t_stack;

typedef struct	s_errors
{
	unsigned int	mask;
	char			*strerror;
}				t_errors;

int		parse(t_game *data, const char *path);

int		parse_texture(t_game *data, const char *id, char *line);
int		parse_color(t_game *data, const char *id, char *line);
int		parse_resolution(t_game *data, const char *id, char *line);

char	*skip_spaces(const char *s);
char	*skip_char(const char *s, unsigned char c);
char	*skip_digits(const char *s);
int		has_valid_ext(const char *path);
void	freeline(t_game *data);
int		is_mapline(const char *line);
void	map_processor(t_game *data);
int		map_is_valid(t_game *data);

t_stack	*Stack_new_node(t_vec pos);
t_stack *Stack_push(t_stack **root, t_vec pos);
t_vec	Stack_pop(t_stack **root);
t_vec	Stack_peek(t_stack *root);
int 	Stack_height(t_stack *root);
void	Stack_free(t_stack **root);

void 	String_array_free(char **strs, int size);
char	**String_array_copy(char **strs, int size);

int		Errors_print(unsigned int errors, int listall);

# define ID_SIZE 8
# define RGB_SIZE 3
# define CALLBACKS_SIZE 3
# define ERR_ARRAY_SIZE 14
# define SPECS_NUMBER 8


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
	{ID_NORTH, TEXTURE_INDEX, 1},
	{ID_SOUTH, TEXTURE_INDEX, 1U << 1},
	{ID_EAST, TEXTURE_INDEX, 1U << 2},
	{ID_WEST, TEXTURE_INDEX, 1U << 3},
	{ID_SPRITE, TEXTURE_INDEX, 1U << 4},
	{ID_RES, RESOLUTION_INDEX, 1U << 5},
	{ID_FLOOR, COLOR_INDEX, 1U << 6},
	{ID_CEIL, COLOR_INDEX, 1U << 7}
};

static int (*parse_callbacks[CALLBACKS_SIZE])(t_game*, const char*, char*) = {
	parse_color,
	parse_resolution,
	parse_texture
};

# define RET_ERROR 1
# define RET_NO_ERROR 0
# define MAP_EXT ".cub"

// Charset definition
# define ERROR_BASE_MSG "Error\n"
# define COMMA ','
# define SPACE ' '
# define MAP_CHARSET "012NSEW"
# define MAP_CHARSET_EXTEND "012NSEW "
# define EMPTY '0'
# define REPLACE_COLOR 'x'
# define TARGET_COLOR '0'
# define TARGET_COLORS "02NSEW"
# define DELTA_SIZE 4

enum	e_err_code
{
	CODE_ERR_MAP_CLOSE_ERROR		= (1U),
	CODE_ERR_MAP_CONFIG_ERROR		= (1U << 1),
	CODE_ERR_COLOR_OUT_OF_RANGE 	= (1U << 2),
	CODE_ERR_COLOR_MISSING			= (1U << 3),
	CODE_ERR_COLOR_BAD_FORMAT		= (1U << 4),
	CODE_ERR_TEXTURE_BAD_INDENT 	= (1U << 5),
	CODE_ERR_RESOLUTION_MISSING		= (1U << 6),
	CODE_ERR_CONF_OPEN_ERROR		= (1U << 7),
	CODE_ERR_BAD_FILE_EXT			= (1U << 8),
	CODE_ERR_INCONSISTENT_SPECS 	= (1U << 9),
	CODE_ERR_BAD_CHARS_IN_COLORS	= (1U << 10),
	CODE_ERR_DUPLICATE_SPECS		= (1U << 11),
	CODE_ERR_TEXTURE_PATH_MISSING	= (1U << 12),
	CODE_ERR_BAD_SPEC				= (1U << 13),
};

static const t_errors errors_array[ERR_ARRAY_SIZE] = {
	{CODE_ERR_MAP_CLOSE_ERROR, "Map isn't closed properly"},
	{CODE_ERR_MAP_CONFIG_ERROR, "Map contains incorrect characters"},
	{CODE_ERR_COLOR_OUT_OF_RANGE, "Color out of range, should be [0 ; 255]"},
	{CODE_ERR_COLOR_MISSING, "Missing color"},
	{CODE_ERR_COLOR_BAD_FORMAT, "Color not well formatted"},
	{CODE_ERR_TEXTURE_BAD_INDENT, "Texture bad indented"},
	{CODE_ERR_RESOLUTION_MISSING, "Resolution is missing one parameter"},
	{CODE_ERR_CONF_OPEN_ERROR, "Error while opening configuration file"},
	{CODE_ERR_BAD_FILE_EXT, "File extension not valid, .cub expected"},
	{CODE_ERR_INCONSISTENT_SPECS, "Inconsistent number of specifiers"},
	{CODE_ERR_BAD_CHARS_IN_COLORS, "Bad characters in color field"},
	{CODE_ERR_DUPLICATE_SPECS, "Duplicate specs"},
	{CODE_ERR_TEXTURE_PATH_MISSING, "Texture path is missing"},
	{CODE_ERR_BAD_SPEC, "Bad specifier"}
};

#endif