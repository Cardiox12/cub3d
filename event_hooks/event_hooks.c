/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 00:44:00 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/01 02:45:22 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"
#include "event_hooks.h"
#include "bitmap.h"

int		key_pressed(int keycode, t_game *data)
{
	if (keycode == KEY_ESC)
	{
		if (data->save)
			export_to_bmp(SAVE_NAME, data);
		mlx_destroy_image(
			data->infos.mlx_ptr,
			data->image.img_ref
		);
		exit(0);
	}
	event_array[keycode] = TRUE;
	return (0);
}

int		key_released(int keycode, t_game *data)
{
	(void)data;
	event_array[keycode] = FALSE;
	return (0);
}

int		exit_hook(t_game *data)
{
	if (data->save)
		export_to_bmp(SAVE_NAME, data);
	mlx_destroy_image(
		data->infos.mlx_ptr,
		data->image.img_ref
	);
	exit(0);
}

int		motion_hook(int x, int y, t_game *data)
{
	(void)data;
	(void)x;
	(void)y;
	return (0);
}