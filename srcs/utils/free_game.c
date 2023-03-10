/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 21:20:00 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 23:01:28 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	free_map(t_game *data)
{
	int index;

	index = 0;
	while (index < data->map.map_ysize)
	{
		if (data->map.map[index] != NULL)
			free(data->map.map[index]);
		index++;
	}
}

static void	free_textures(t_game *data)
{
	int index;

	index = 0;
	while (index < TEX_NUMBERS)
	{
		if (data->map.textures[index].image.img_ref != NULL)
		{
			mlx_destroy_image(
				data->infos.mlx_ptr,
				data->map.textures[index].image.img_ref);
		}
		index++;
	}
}

void		free_game(t_game *data)
{
	if (data->camera.zbuffer != NULL)
		free(data->camera.zbuffer);
	if (data->camera.sprite_distance != NULL)
		free(data->camera.sprite_distance);
	if (data->camera.sprite_order != NULL)
		free(data->camera.sprite_order);
	if (data->infos.win_ptr != NULL)
	{
		mlx_destroy_window(
			data->infos.mlx_ptr,
			data->infos.win_ptr);
	}
	if (data->image.img_ref != NULL)
	{
		mlx_destroy_image(
			data->infos.mlx_ptr,
			data->image.img_ref);
	}
	free_map(data);
	free_textures(data);
}
