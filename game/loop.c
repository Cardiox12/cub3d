/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:23:36 by bbellavi          #+#    #+#             */
/*   Updated: 2020/03/12 18:02:26 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_hooks.h"
#include "cub3d.h"
#include "render.h"

void	check_event(t_game *data)
{
	if (event_array[I_KEY_DOWN])
		data->camera.posY += (STEP * (float)SQUARE_SIZE);
	else if (event_array[I_KEY_UP])
		data->camera.posY -= (STEP * (float)SQUARE_SIZE);
	else if (event_array[I_KEY_LEFT])
		data->camera.posX -= (STEP * (float)SQUARE_SIZE);
	else if (event_array[I_KEY_RIGHT])
		data->camera.posX += (STEP * (float)SQUARE_SIZE);
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