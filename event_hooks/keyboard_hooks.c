/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 00:44:00 by bbellavi          #+#    #+#             */
/*   Updated: 2020/03/06 19:06:15 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"
#include "event_hooks.h"
#define STEP (1.0f/1000.0f)

int     keyboard_hook(int keycode, t_game *data)
{
	if (keycode == KEY_DOWN)
		data->camera.posY += (STEP * (float)SQUARE_SIZE);
	else if (keycode == KEY_UP)
		data->camera.posY -= (STEP * (float)SQUARE_SIZE);
	else if (keycode == KEY_LEFT)
		data->camera.posX -= (STEP * (float)SQUARE_SIZE);
	else if (keycode == KEY_RIGHT)
		data->camera.posX += (STEP * (float)SQUARE_SIZE);
	else if (keycode == KEY_ESC)
	{
		mlx_destroy_image(
			data->infos.mlx_ptr,
			data->image.img_ref
		);
		exit(0);
	}
    return (0);
}