/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:23:36 by bbellavi          #+#    #+#             */
/*   Updated: 2020/03/14 15:10:51 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_hooks.h"
#include "cub3d.h"
#include "render.h"

#include <stdio.h>

// void	check_event(t_game *data)
// {
// 	if (event_array[I_KEY_DOWN])
// 		data->camera.pos.y += (STEP * (float)SQUARE_SIZE);
// 	else if (event_array[I_KEY_UP])
// 		data->camera.pos.y -= (STEP * (float)SQUARE_SIZE);
// 	else if (event_array[I_KEY_LEFT])
// 		data->camera.pos.x -= (STEP * (float)SQUARE_SIZE);
// 	else if (event_array[I_KEY_RIGHT])
// 		data->camera.pos.x += (STEP * (float)SQUARE_SIZE);
// }

void	check_event(t_game *data)
{
	
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