/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:23:36 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 15:45:18 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_hooks.h"
#include "cub3d.h"
#include "render.h"

void	check_event(t_game *data)
{
	if (g_event_array[KEY_S])
		player_move_down(data);
	if (g_event_array[KEY_W])
		player_move_up(data);
	if (g_event_array[KEY_A])
		player_move_left(data);
	if (g_event_array[KEY_D])
		player_move_right(data);
	if (g_event_array[KEY_LEFT] || g_event_array[KEY_RIGHT])
		player_rotate(data);
	if (g_event_array[KEY_SHIFT])
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