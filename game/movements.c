/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 20:42:29 by tony              #+#    #+#             */
/*   Updated: 2020/05/07 07:50:39 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_hooks.h"
#include "types.h"

int		is_out_of_bound(t_vec2 pos, t_game *data)
{
	const int x = pos.x;
	const int y = pos.y;
	
	if (x >= 0 && x < data->map.map_xsize && y >= 0 && y < data->map.map_ysize)
	{
		if (data->map.map[y][x] == WALL)
			return (TRUE);
	}
	return (FALSE);
}

void	player_move_down(t_game *data)
{
	const float		stepsize = STEP * (float)SQUARE_SIZE;
	const t_vec2	front = neg_vec2(mult_vec2(data->camera.plan_front, stepsize));
	t_vec2			tmp;

	tmp = add_vec2(data->camera.pos, front);
	if (is_out_of_bound(tmp, data) == FALSE)
	{
		data->camera.pos = tmp;
		Rays_update(data->camera.rays, tmp);
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
		Rays_update(data->camera.rays, tmp);
	}
}

void	player_move_left(t_game *data)
{
	const float		stepsize = STEP * (float)SQUARE_SIZE;
	const t_vec2	right = neg_vec2(mult_vec2(data->camera.plan_right, stepsize));
	t_vec2			tmp;

	tmp = add_vec2(data->camera.pos, right);
	if (is_out_of_bound(tmp, data) == FALSE)
	{
		data->camera.pos = tmp;
		Rays_update(data->camera.rays, tmp);
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
		Rays_update(data->camera.rays, tmp);
	}
}

void	player_rotate(t_game *data)
{
	char		dir;

	data->camera.camera_angle += (event_array[KEY_A]) ? -to_radians(1) : to_radians(1);
	dir = (event_array[KEY_A]) ? ANTI_CLOCKWISE : CLOCKWISE;
	data->camera.plan_front = rotate(data->camera.plan_front, to_radians(1), dir);
	data->camera.plan_right = rotate(data->camera.plan_right, to_radians(1), dir);
	data->camera.plane = rotate(data->camera.plane, to_radians(1), dir);
	Rays_rotate(data->camera.rays, to_radians(1), dir);
}