/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:33:14 by bbellavi          #+#    #+#             */
/*   Updated: 2020/03/03 13:03:11 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <stdio.h>

// static int	is_cardinal_point(char c)
// {
// 	return (c == S_SOUTH || c == S_NORTH || c == S_EAST || c == S_WEST);
// }

void	set_heading(t_camera *player, char cardinal_p)
{
	if (cardinal_p == S_SOUTH)
	{
		player->planX = 0;
		player->planY = 1;
	}
	else if (cardinal_p == S_NORTH)
	{
		player->heading = D_NORTH;
		player->planX = 0;
		player->planY = -1;
	}
	else if (cardinal_p == S_WEST)
	{
		player->planX = -1;
		player->planY = 0;
	}
	else if (cardinal_p == S_EAST)
	{
		player->planX = 1;
		player->planY = 0;
	}
}

void	raycasting(t_game __unused *data)
{

}

void	render(t_game *data)
{
	data->image.img_ref = mlx_new_image(
			data->infos.mlx_ptr,
			data->map.resolution.x,
			data->map.resolution.y);
	data->image.img_data_addr = (int*)mlx_get_data_addr(
		data->image.img_ref,
		&data->image.bits_per_pixel,
		&data->image.line_size,
		&data->image.endian);
		
	draw_ceil_and_floor(data);

	mlx_put_image_to_window(
		data->infos.mlx_ptr,
		data->infos.win_ptr,
		data->image.img_ref,
		0,
		0
	);
	mlx_destroy_image(
		data->infos.mlx_ptr,
		data->image.img_ref
	);
	// raycasting(data);
}