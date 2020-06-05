/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 20:42:29 by tony              #+#    #+#             */
/*   Updated: 2020/06/05 17:41:36 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_hooks.h"
#include "types.h"

void	player_move_down(t_game *data)
{
	const float		stepsize = STEP * (float)SQUARE_SIZE;
	t_vec2			front;
	t_vec2			tmp;

	front = neg_vec2(mult_vec2(data->camera.plan_front, stepsize));
	tmp = add_vec2(data->camera.pos, front);
	if (is_out_of_bound(tmp, data) == FALSE)
	{
		data->camera.pos = tmp;
		rays_update(data->camera.rays, tmp);
	}
}

void	player_move_up(t_game *data)
{
	const float		stepsize = STEP * (float)SQUARE_SIZE;
	const t_vec2	front = mult_vec2(data->camera.plan_front, stepsize);
	t_vec2			tmp;

	tmp = add_vec2(data->camera.pos, front);
	if (is_out_of_bound(tmp, data) == FALSE)
	{
		data->camera.pos = tmp;
		rays_update(data->camera.rays, tmp);
	}
}

void	player_move_left(t_game *data)
{
	const float		stepsize = STEP * (float)SQUARE_SIZE;
	t_vec2			right;
	t_vec2			tmp;

	right = neg_vec2(mult_vec2(data->camera.plan_right, stepsize));
	tmp = add_vec2(data->camera.pos, right);
	if (is_out_of_bound(tmp, data) == FALSE)
	{
		data->camera.pos = tmp;
		rays_update(data->camera.rays, tmp);
	}
}

void	player_move_right(t_game *data)
{
	const float		stepsize = STEP * (float)SQUARE_SIZE;
	const t_vec2	right = mult_vec2(data->camera.plan_right, stepsize);
	t_vec2			tmp;

	tmp = add_vec2(data->camera.pos, right);
	if (is_out_of_bound(tmp, data) == FALSE)
	{
		data->camera.pos = tmp;
		rays_update(data->camera.rays, tmp);
	}
}

void	player_rotate(t_game *data)
{
	char dir;

	if (g_event_array[KEY_LEFT])
	{
		if (data->camera.camera_angle == 0)
			data->camera.camera_angle = 359;
		else
			data->camera.camera_angle = abs(
				(int)(data->camera.camera_angle - 1)) % 360;
		dir = ANTI_CLOCKWISE;
	}
	else
	{
		dir = CLOCKWISE;
		data->camera.camera_angle = abs((int)(
			data->camera.camera_angle + 1)) % 360;
	}
	data->camera.plan_front = rotate(data->camera.plan_front,
	to_radians(1), dir);
	data->camera.plan_right = rotate(data->camera.plan_right,
	to_radians(1), dir);
	rays_rotate(data->camera.rays, to_radians(1), dir);
}
