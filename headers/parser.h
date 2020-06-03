/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 02:01:35 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/03 16:58:44 by bbellavi         ###   ########.fr       */
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
#include "errors.h"

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
int		map_processor(t_game *data);
int		map_is_valid(t_game *data);
int		is_spec(const char *id);

t_stack	*Stack_new_node(t_vec pos);
t_stack *Stack_push(t_stack **root, t_vec pos);
t_vec	Stack_pop(t_stack **root);
t_vec	Stack_peek(t_stack *root);
int 	Stack_height(t_stack *root);
void	Stack_free(t_stack **root);

void 	String_array_free(char **strs, int size);
char	**String_array_copy(char **strs, int size);

int		Errors_print(unsigned int errors, int listall);
void	parse_sprites(t_game *data);
int		cmd_parse(t_game *data, const char *cmd);
int		is_empty_line(t_game *data);
int		check_eof(t_game *data, int fd);

# define ID_SIZE 8
# define RGB_SIZE 3
# define CALLBACKS_SIZE 3
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

static const t_id ids[ID_SIZE] = {
	{ID_NORTH, TEXTURE_INDEX, 1},
	{ID_SOUTH, TEXTURE_INDEX, 1U << 1},
	{ID_EAST, TEXTURE_INDEX, 1U << 2},
	{ID_WEST, TEXTURE_INDEX, 1U << 3},
	{ID_SPRITE, TEXTURE_INDEX, 1U << 4},
	{ID_RES, RESOLUTION_INDEX, 1U << 5},
	{ID_FLOOR, COLOR_INDEX, 1U << 6},
	{ID_CEIL, COLOR_INDEX, 1U << 7}
};

typedef int (*callbacks)(t_game*, const char*, char*);

static const callbacks parse_callbacks[CALLBACKS_SIZE] = {
	parse_color,
	parse_resolution,
	parse_texture
};

// Charset definition
# define MAP_EXT ".cub"
# define CMD_SAVE "--save"
# define ERROR_BASE_MSG "Error\n"
# define COMMA ','
# define SPACE ' '
# define MAP_CHARSET "012NSEW"
# define MAP_CHARSET_EXTEND "012NSEW "
# define EMPTY '0'
# define REPLACE_COLOR 'x'
# define TARGET_COLOR '0'
# define PREPROCESS_REPLACE_COLOR '9'
# define TARGET_COLORS "02NSEW9"
# define DELTA_SIZE 4
# define SPRITE_CHAR '2'

#endif