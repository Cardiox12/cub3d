/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 21:07:14 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 21:09:32 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int		sort_sprites(int *order, double *dist, int amount)
{
	t_pair	*pairs;
	int		i;

	i = 0;
	pairs = malloc(sizeof(t_pair) * amount);
	if (pairs == NULL)
		return (RET_ERROR);
	while (i < amount)
	{
		pairs[i].val = dist[i];
		pairs[i].index = order[i];
		i++;
	}
	sort_pairs(pairs, amount);
	i = 0;
	while (i < amount)
	{
		dist[i] = pairs[i].val;
		order[i] = pairs[i].index;
		i++;
	}
	free(pairs);
	return (RET_NO_ERROR);
}

void	sort_sprites_dist(t_game *data)
{
	int i;

	i = 0;
	while (i < data->map.sprites.cursor)
	{
		data->camera.sprite_order[i] = i;
		data->camera.sprite_distance[i] = (
			pow(data->camera.pos.x - data->map.sprites.sprites[i].pos.x, 2)
			+ pow(data->camera.pos.y - data->map.sprites.sprites[i].pos.y, 2));
		i++;
	}
	sort_sprites(data->camera.sprite_order, data->camera.sprite_distance,
	data->map.sprites.cursor);
}
