/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 00:44:00 by bbellavi          #+#    #+#             */
/*   Updated: 2020/03/06 14:26:32 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"
#include "event_hooks.h"
#define ESC_KEY 53

int     keyboard_hook(int keycode, t_game *data)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_image(
			data->infos.mlx_ptr,
			data->image.img_ref
		);
		exit(0);
	}
    return (0);
}