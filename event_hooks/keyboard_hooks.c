/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 00:44:00 by bbellavi          #+#    #+#             */
/*   Updated: 2020/04/24 15:13:28 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"
#include "event_hooks.h"

int		key_pressed(int keycode, t_game *data)
{
	if (keycode == KEY_ESC)
	{
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