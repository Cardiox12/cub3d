/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 22:39:22 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/21 07:18:44 by bbellavi         ###   ########.fr       */
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

int		map_is_valid(t_game *data)
{
	const int	dx[DELTA_SIZE] = {0, 1, 0, -1};
	const int	dy[DELTA_SIZE] = {-1, 0, 1, 0};
	int			index;
	t_stack		*stack;
	t_vec		n;

	stack = NULL;
	get_starting_point(data);

	if (data->map.map[(int)data->camera.pos.y][(int)data->camera.pos.x] == TARGET_COLOR)
		return (FALSE);
	if (data->map.map[(int)data->camera.pos.y][(int)data->camera.pos.x] != 'N')
		return (FALSE);

	Stack_push(&stack, to_vec(data->camera.pos));

	while (Stack_height(stack) != 0)
	{
		t_vec pos = Stack_pop(&stack);

		data->map.map[pos.y][pos.x] = REPLACE_COLOR;

		index = 0;
		while (index < DELTA_SIZE)
		{
			n = (t_vec){pos.x + dx[index], pos.y + dy[index]};
			if (n.x >= 0 && n.x < data->map.map_xsize && n.y >= 0 && n.y < data->map.map_ysize)
			{
				if (data->map.map[n.y][n.x] == TARGET_COLOR)
					Stack_push(&stack, n);
			}
			else
			{
				return (FALSE);
			}
			index++;
		}
	}
	return (TRUE);
}