/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 22:39:22 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/21 21:33:36 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"


void	map_processor(t_game *data)
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
			if (data->map.map[i.y][i.x] == SPACE || data->map.map[i.y][i.x] == '\0')
				data->map.map[i.y][i.x] = EMPTY;
			i.x++;
		}
		i.y++;
	}
}

static void	free_objects(t_game *data, char **map, t_stack **stack)
{
	String_array_free(map, data->map.map_ysize);
	Stack_free(stack);
	free(*stack);
	free(map);
}

int		map_is_valid(t_game *data)
{
	t_vec	n;
	t_vec	pos;
	t_stack	*stack;
	int		index;
	char	**map;

	stack = NULL;
	map  = String_array_copy(data->map.map, data->map.map_ysize);
	get_starting_point(data);
	Stack_push(&stack, to_vec(data->camera.pos));
	while (Stack_height(stack) != 0)
	{
		pos = Stack_pop(&stack);
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
					Stack_push(&stack, n);
			}
			else
			{
				free_objects(data, map, &stack);
				return (FALSE);
			}
			index++;
		}
	}
	free_objects(data, map, &stack);
	return (TRUE);
}