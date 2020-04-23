/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:23:36 by bbellavi          #+#    #+#             */
/*   Updated: 2020/04/23 18:16:32 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_hooks.h"
#include "cub3d.h"
#include "render.h"

#include <stdio.h>

void	check_event(t_game *data)
{
	char dir;

	if (event_array[KEY_DOWN])
		data->camera.pos.y += (STEP * (float)SQUARE_SIZE);
	else if (event_array[KEY_UP])
		data->camera.pos.y -= (STEP * (float)SQUARE_SIZE);
	else if (event_array[KEY_LEFT])
		data->camera.pos.x -= (STEP * (float)SQUARE_SIZE);
	else if (event_array[KEY_RIGHT])
		data->camera.pos.x += (STEP * (float)SQUARE_SIZE);
	else if (event_array[KEY_A] || event_array[KEY_D])
	{
		data->camera.camera_angle += (event_array[KEY_A]) ? -to_radians(1) : to_radians(1);
		dir = (event_array[KEY_A]) ? ANTI_CLOCKWISE : CLOCKWISE;
		data->camera.plan = rotate(data->camera.plan, to_radians(1), dir);
	}
}

int		loop(t_game *data)
{
	render(data);
	check_event(data);
	mlx_put_image_to_window(
		data->infos.mlx_ptr,
		data->infos.win_ptr,
		data->image.img_ref,
		0,
		0
	);
	return (0);
}