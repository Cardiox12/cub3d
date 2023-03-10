/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 17:42:04 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 22:56:41 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_sprites(t_game *data)
{
	int		index;
	t_vec	i;

	i.y = 0;
	data->map.sprites.cursor = 0;
	while (i.y < data->map.map_ysize)
	{
		i.x = 0;
		while (i.x < data->map.map_xsize)
		{
			if (data->map.map[i.y][i.x] == SPRITE_CHAR)
			{
				index = data->map.sprites.cursor;
				data->map.sprites.sprites[index] = (t_sprite){
				(t_vec2){i.x + 0.5, i.y + 0.5}, IDX_SPRITE, 1, 1, 64};
				data->map.sprites.cursor++;
			}
			i.x++;
		}
		i.y++;
	}
}
