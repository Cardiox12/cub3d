/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:23:36 by bbellavi          #+#    #+#             */
/*   Updated: 2020/04/14 16:58:32 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_hooks.h"
#include "cub3d.h"
#include "render.h"

#include <stdio.h>

void	check_event(t_game *data)
{
	if (event_array[KEY_DOWN])
		data->camera.pos.y += (STEP * (float)SQUARE_SIZE);
	else if (event_array[KEY_UP])
		data->camera.pos.y -= (STEP * (float)SQUARE_SIZE);
	else if (event_array[KEY_LEFT])
		data->camera.pos.x -= (STEP * (float)SQUARE_SIZE);
	else if (event_array[KEY_RIGHT])
		data->camera.pos.x += (STEP * (float)SQUARE_SIZE);
	else if (event_array[KEY_A])
	{
		data->camera.camera_angle -= to_radians(1);
		printf("angle : %f\n", data->camera.camera_angle);
		data->camera.plan = rotate(data->camera.plan, to_radians(data->camera.camera_angle));
	}
	else if (event_array[KEY_D])
	{
		data->camera.camera_angle += to_radians(1);
		printf("angle : %f\n", data->camera.camera_angle);
		data->camera.plan = rotate(data->camera.plan, to_radians(data->camera.camera_angle));
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