/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:23:36 by bbellavi          #+#    #+#             */
/*   Updated: 2020/03/06 14:25:37 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"

int		loop(t_game *data)
{
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