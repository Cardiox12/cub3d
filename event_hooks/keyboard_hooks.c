/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 00:44:00 by bbellavi          #+#    #+#             */
/*   Updated: 2020/03/12 13:39:47 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"
#include "event_hooks.h"

int		get_event_index(int keycode)
{
	if (keycode == KEY_DOWN)
		return (I_KEY_DOWN);
	else if (keycode == KEY_UP)
		return (I_KEY_UP);
	else if (keycode == KEY_LEFT)
		return (I_KEY_LEFT);
	else if (keycode == KEY_RIGHT)
		return (I_KEY_RIGHT);
	return (-1);
}

int		key_pressed(int keycode, t_game *data)
{
	const int index = get_event_index(keycode);

	if (index != -1)
		event_array[index] = TRUE;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(
			data->infos.mlx_ptr,
			data->image.img_ref
			);
		exit(0);
	}
	return (0);
}

int		key_released(int keycode, t_game *data)
{
	const int index = get_event_index(keycode);

	(void)data;
	if (index != -1)
		event_array[index] = FALSE;
	return (0);
}