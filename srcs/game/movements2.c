/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 17:37:45 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 17:42:48 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_hooks.h"
#include "types.h"

int		is_sprite(t_vec2 pos, t_game *data)
{
	return (data->map.map[(int)pos.y][(int)pos.x] == '2');
}

int		is_out_of_bound(t_vec2 pos, t_game *data)
{
	const int x = pos.x;
	const int y = pos.y;

	if (x >= 0 && x < data->map.map_xsize && y >= 0 && y < data->map.map_ysize)
	{
		if (is_wall(data->map.map[y][x]) || is_sprite(pos, data))
			return (TRUE);
	}
	return (FALSE);
}
