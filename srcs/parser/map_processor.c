/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 22:39:22 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/04 21:29:31 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	free_objects(t_game *data, char **map, t_stack **stack)
{
	String_array_free(map, data->map.map_ysize);
	Stack_free(stack);
}

int			map_processor(t_game *data)
{
	size_t	curlen;
	t_vec	i;

	i.y = 0;
	while (i.y < data->map.map_ysize)
	{
		curlen = ft_strlen(data->map.map[i.y]);
		if (curlen < (size_t)data->map.map_xsize)
			data->map.map[i.y] = ft_realloc(data->map.map[i.y], curlen, data->map.map_xsize + 1);
		i.x = 0;
		while (i.x < data->map.map_xsize)
		{
			if (ft_strchr(MAP_CHARSET_EXTEND, data->map.map[i.y][i.x]) == NULL)
				return (CODE_ERR_BAD_CHAR_IN_MAP);
			if (data->map.map[i.y][i.x] == SPACE || data->map.map[i.y][i.x] == '\0')
				data->map.map[i.y][i.x] = PREPROCESS_REPLACE_COLOR;
			i.x++;
		}
		i.y++;
	}
	return (RET_NO_ERROR);
}

int			flood_fill(t_game *data, t_stack **stack, char **map)
{
	t_vec	pos;
	t_vec	n;
	int		index;

	pos = Stack_pop(stack);
	map[pos.y][pos.x] = REPLACE_COLOR;
	index = 0;
	while (index < DELTA_SIZE)
	{
		n = (t_vec){
			pos.x + (int[DELTA_SIZE]){0, 1, 0, -1}[index], 
			pos.y + (int[DELTA_SIZE]){-1, 0, 1, 0}[index]
		};
		if (n.x >= 0 && n.x < data->map.map_xsize && n.y >= 0 && n.y < data->map.map_ysize)
		{
			if (ft_strchr(TARGET_COLORS, map[n.y][n.x]) != NULL)
				Stack_push(stack, n);
		}
		else
		{
			free_objects(data, map, stack);
			return (FALSE);
		}
		index++;
	}
	return (TRUE);
}

int		map_is_valid(t_game *data)
{
	t_stack			*stack;
	char			**map;
	unsigned int	errors;

	stack = NULL;
	map  = String_array_copy(data->map.map, data->map.map_ysize);
	if ((errors = get_starting_point(data)))
	{
		String_array_free(map, data->map.map_ysize);
		return (errors);
	}
	Stack_push(&stack, to_vec(data->camera.pos));
	while (Stack_height(stack) != 0)
	{
		if (flood_fill(data, &stack, map) == FALSE)
			return (CODE_ERR_MAP_CLOSE_ERROR);
	}
	free_objects(data, map, &stack);
	return (RET_NO_ERROR);
}

int	check_eof(t_game *data, int fd)
{
	if (data->map.line != NULL)
	{
		if (is_empty_line(data))
			return (CODE_ERR_NON_EMPTY_LINE_AT_EOF);
	}
	while (get_next_line(fd, &data->map.line) > 0)
	{
		if (is_empty_line(data))
			return (CODE_ERR_NON_EMPTY_LINE_AT_EOF);
	}
	if (data->map.line != NULL)
	{
		if (is_empty_line(data))
			return (CODE_ERR_NON_EMPTY_LINE_AT_EOF);
	}
	return (RET_NO_ERROR);
}