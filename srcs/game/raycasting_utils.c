/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 21:15:57 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 21:20:02 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int		texture_choser(t_game *data)
{
	const int angle = vector_angle(data->camera.ray_dir);

	if (data->camera.side == 1 && (angle >= 0 && angle < 180))
		return (IDX_NORTH);
	if (data->camera.side == 1 && (angle >= 180 && angle <= 360))
		return (IDX_SOUTH);
	if (data->camera.side == 0 && (angle > 90 && angle < 270))
		return (IDX_EAST);
	if (data->camera.side == 0 && ((angle >= 270 && angle <= 360) ||
	(angle >= 0 && angle <= 90)))
		return (IDX_WEST);
	return (IDX_NORTH);
}

void	get_side(t_game *data)
{
	if (data->camera.ray_dir.x < 0)
	{
		data->camera.step.x = -1;
		data->camera.side_dist.x = (data->camera.pos.x - data->camera.map_pos.x)
		* data->camera.delta_dist.x;
	}
	else
	{
		data->camera.step.x = 1;
		data->camera.side_dist.x = (data->camera.map_pos.x + 1.0
		- data->camera.pos.x) * data->camera.delta_dist.x;
	}
	if (data->camera.ray_dir.y < 0)
	{
		data->camera.step.y = -1;
		data->camera.side_dist.y = (data->camera.pos.y - data->camera.map_pos.y)
		* data->camera.delta_dist.y;
	}
	else
	{
		data->camera.step.y = 1;
		data->camera.side_dist.y = (data->camera.map_pos.y + 1.0
		- data->camera.pos.y) * data->camera.delta_dist.y;
	}
}
