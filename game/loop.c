/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:23:36 by bbellavi          #+#    #+#             */
/*   Updated: 2020/04/29 18:36:53 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_hooks.h"
#include "cub3d.h"
#include "render.h"

#include <stdio.h>

void	check_event(t_game *data)
{
	const float stepsize = STEP * (float)SQUARE_SIZE;
	t_vec2 front;
	t_vec2 right;
	char dir;

	if (event_array[KEY_DOWN])
	{
		front = neg_vec2(mult_vec2(data->camera.plan_front, stepsize));
		data->camera.pos = add_vec2(data->camera.pos, front);
		Rays_update(data->camera.rays, data->camera.pos);
	}
	else if (event_array[KEY_UP])
	{
		front = mult_vec2(data->camera.plan_front, stepsize);
		data->camera.pos = add_vec2(data->camera.pos, front);
		Rays_update(data->camera.rays, data->camera.pos);
	}
	else if (event_array[KEY_LEFT])
	{
		right = neg_vec2(mult_vec2(data->camera.plan_right, stepsize));
		data->camera.pos = add_vec2(data->camera.pos, right);
		Rays_update(data->camera.rays, data->camera.pos);
	}
	else if (event_array[KEY_RIGHT])
	{
		right = mult_vec2(data->camera.plan_right, stepsize);
		data->camera.pos = add_vec2(data->camera.pos, right);
		Rays_update(data->camera.rays, data->camera.pos);
	}
	else if (event_array[KEY_A] || event_array[KEY_D])
	{
		data->camera.camera_angle += (event_array[KEY_A]) ? -to_radians(1) : to_radians(1);
		dir = (event_array[KEY_A]) ? ANTI_CLOCKWISE : CLOCKWISE;
		data->camera.plan_front = rotate(data->camera.plan_front, to_radians(1), dir);
		data->camera.plan_right = rotate(data->camera.plan_right, to_radians(1), dir);

		Rays_rotate(data->camera.rays, to_radians(1), dir);
	}
	else if (event_array[KEY_SHIFT])
		data->camera.debug = (data->camera.debug) ? FALSE : TRUE;
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