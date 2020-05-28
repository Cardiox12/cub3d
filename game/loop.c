/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:23:36 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/28 02:40:25 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_hooks.h"
#include "cub3d.h"
#include "render.h"

void	check_event(t_game *data)
{
	if (event_array[KEY_S])
		player_move_down(data);
	else if (event_array[KEY_W])
		player_move_up(data);
	else if (event_array[KEY_A])
		player_move_left(data);
	else if (event_array[KEY_D])
		player_move_right(data);
	else if (event_array[KEY_LEFT] || event_array[KEY_RIGHT])
		player_rotate(data);
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