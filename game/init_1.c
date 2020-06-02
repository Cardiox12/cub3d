/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 17:35:27 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/03 00:47:43 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "errors.h"

int	init_textures(t_game *data)
{
	t_texture	*text = data->map.textures;
	int			index;

	index = 0;
	while (index < TEX_NUMBERS)
	{
		text[index].image.img_ref = mlx_xpm_file_to_image(
			data->infos.mlx_ptr,
			text[index].path,
			&text[index].width,
			&text[index].height
		);
		if (text[index].image.img_ref == NULL)
			return (CODE_ERR_LOADING_TEXTURE);
		text[index].image.img_data_addr = (int*)mlx_get_data_addr(
			text[index].image.img_ref,
			&text[index].image.bits_per_pixel,
			&text[index].image.line_size,
			&text[0].image.endian
		);
		index++;
	}
	return (RET_NO_ERROR);
}

int	init_game(t_game *data)
{
	unsigned int minres;
	unsigned int minsize;

	if ((data->infos.mlx_ptr = mlx_init()) == NULL)
		return (CODE_ERR_MLX_FAILED_TO_INIT);
	check_screen_size(data);
	minres = min(data->map.resolution.x, data->map.resolution.y);
	minsize = min(data->map.map_xsize, data->map.map_ysize);
	data->infos.win_ptr = mlx_new_window(
		data->infos.mlx_ptr,
		data->map.resolution.x,
		data->map.resolution.y,
		WINDOW_NAME
	);
	if (data->infos.win_ptr == NULL)
		return (CODE_ERR_WIN_FAILED_TO_INIT);
	data->camera.field_of_view = FIELD_OF_VIEW;
	data->camera.debug = FALSE;
	data->map.specs_number = 0;
	data->minimap.size = minres * ((float)MINIMAP_RATIO / 100);
	data->minimap.square_size = data->minimap.size / minsize;
	get_starting_point(data);
	return (RET_NO_ERROR);
}

int	init_game_image(t_game *data)
{
	data->image.img_ref = mlx_new_image(
			data->infos.mlx_ptr,
			data->map.resolution.x,
			data->map.resolution.y);
	if (data->image.img_ref == NULL)
		return (CODE_ERR_IMG_FAILED_TO_INIT);
	data->image.img_data_addr = (int*)mlx_get_data_addr(
		data->image.img_ref,
		&data->image.bits_per_pixel,
		&data->image.line_size,
		&data->image.endian);
	data->image.line_count = data->map.resolution.y;
	return (RET_NO_ERROR);
}

int	init_sprite_variables(t_game *data)
{
	data->camera.ZBuffer = malloc(sizeof(double) * data->map.resolution.x);
	if (data->camera.ZBuffer == NULL)
		return (RET_ERROR);
	data->camera.sprite_order = malloc(sizeof(int) * data->map.sprites.cursor);
	if (data->camera.sprite_order == NULL)
		return (RET_ERROR);
	data->camera.sprite_distance = malloc(sizeof(double) * data->map.sprites.cursor);
	if (data->camera.sprite_order == NULL)
		return (RET_ERROR);
	return (RET_NO_ERROR);
}