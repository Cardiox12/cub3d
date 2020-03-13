/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:23:36 by bbellavi          #+#    #+#             */
/*   Updated: 2020/03/13 14:38:07 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_hooks.h"
#include "cub3d.h"
#include "render.h"

void	check_event(t_game *data)
{
	t_vec result;
	t_vec dir;

	if (event_array[I_KEY_DOWN])
		dir.y = 1;
	else if (event_array[I_KEY_UP])
		dir.y = -1;
	else if (event_array[I_KEY_LEFT])
		dir.x = -1;
	else if (event_array[I_KEY_RIGHT])
		dir.x = 1;
	result = add(
		(t_vec){(int)data->camera.posX + dir.x, (int)data->camera.posY + dir.y},
		(t_vec){(int)data->camera.planX, (int)data->camera.planY}
	);
	if (dir.x != 0 || dir.y != 0)
	{
		data->camera.posX = result.x;
		data->camera.posY = result.y;
	}
	// if (event_array[I_KEY_DOWN])
	// 	data->camera.posY += (STEP * (float)SQUARE_SIZE);
	// else if (event_array[I_KEY_UP])
	// 	data->camera.posY -= (STEP * (float)SQUARE_SIZE);
	// else if (event_array[I_KEY_LEFT])
	// 	data->camera.posX -= (STEP * (float)SQUARE_SIZE);
	// else if (event_array[I_KEY_RIGHT])
	// 	data->camera.posX += (STEP * (float)SQUARE_SIZE);
}

int		loop(t_game *data)
{
	check_event(data);
	render(data);
	mlx_put_image_to_window(
		data->infos.mlx_ptr,
		data->infos.win_ptr,
		data->image.img_ref,
		0,
		0
	);
	return (0);
}