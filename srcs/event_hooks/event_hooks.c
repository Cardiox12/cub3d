/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 00:44:00 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 16:52:01 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "event_hooks.h"
#include "bitmap.h"

static void	quit(t_game *data)
{
	mlx_destroy_image(data->infos.mlx_ptr, data->image.img_ref);
	exit(0);
}

int			key_pressed(int keycode, t_game *data)
{
	if (keycode == KEY_ESC)
		quit(data);
	g_event_array[keycode] = TRUE;
	return (0);
}

int			key_released(int keycode, t_game *data)
{
	(void)data;
	g_event_array[keycode] = FALSE;
	return (0);
}

int			exit_hook(t_game *data)
{
	quit(data);
	return (0);
}

int			motion_hook(int x, int y, t_game *data)
{
	(void)data;
	(void)x;
	(void)y;
	return (0);
}
