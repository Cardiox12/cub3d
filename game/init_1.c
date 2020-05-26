/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 17:35:27 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/25 20:20:32 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"


void	init_textures(t_game *data)
{
	t_texture *text = data->map.textures;

	text[0].image.img_ref = mlx_xpm_file_to_image(data->infos.mlx_ptr, text[0].path, &text[0].width, &text[0].height);
	text[1].image.img_ref = mlx_xpm_file_to_image(data->infos.mlx_ptr, text[1].path, &text[1].width, &text[1].height);
	text[2].image.img_ref = mlx_xpm_file_to_image(data->infos.mlx_ptr, text[2].path, &text[2].width, &text[2].height);
	text[3].image.img_ref = mlx_xpm_file_to_image(data->infos.mlx_ptr, text[3].path, &text[3].width, &text[3].height);
	text[4].image.img_ref = mlx_xpm_file_to_image(data->infos.mlx_ptr, text[4].path, &text[4].width, &text[4].height);
	if (text[0].image.img_ref != NULL && text[1].image.img_ref && text[2].image.img_ref && text[3].image.img_ref && text[4].image.img_ref)
	{
		printf("Sucessfuly loaded textures.\n");
		printf("\tImage : %s of dimensions %ix%i\n", text[0].path, text[0].width, text[0].height);
		printf("\tImage : %s of dimensions %ix%i\n", text[1].path, text[1].width, text[1].height);
		printf("\tImage : %s of dimensions %ix%i\n", text[2].path, text[2].width, text[2].height);
		printf("\tImage : %s of dimensions %ix%i\n", text[3].path, text[3].width, text[3].height);
		printf("\tImage : %s of dimensions %ix%i\n", text[4].path, text[4].width, text[4].height);
	}
	else
	{
		printf("Error with file.\n");
		exit(0);
	}
	text[0].image.img_data_addr = (int*)mlx_get_data_addr(text[0].image.img_ref, &text[0].image.bits_per_pixel, &text[0].image.line_size, &text[0].image.endian);
	text[1].image.img_data_addr = (int*)mlx_get_data_addr(text[1].image.img_ref, &text[1].image.bits_per_pixel, &text[1].image.line_size, &text[1].image.endian);
	text[2].image.img_data_addr = (int*)mlx_get_data_addr(text[2].image.img_ref, &text[2].image.bits_per_pixel, &text[2].image.line_size, &text[2].image.endian);
	text[3].image.img_data_addr = (int*)mlx_get_data_addr(text[3].image.img_ref, &text[3].image.bits_per_pixel, &text[3].image.line_size, &text[3].image.endian);
	text[4].image.img_data_addr = (int*)mlx_get_data_addr(text[4].image.img_ref, &text[4].image.bits_per_pixel, &text[4].image.line_size, &text[3].image.endian);
}

void	init_game(t_game *data)
{
	unsigned int minres;
	unsigned int minsize;

	minres = min(data->map.resolution.x, data->map.resolution.y);
	minsize = min(data->map.map_xsize, data->map.map_ysize);
	data->infos.mlx_ptr = mlx_init();
	data->infos.win_ptr = mlx_new_window(
		data->infos.mlx_ptr,
		data->map.resolution.x,
		data->map.resolution.y,
		WINDOW_NAME
	);
	data->camera.field_of_view = FIELD_OF_VIEW;
	data->camera.debug = FALSE;
	data->map.specs_number = 0;
	data->minimap.size = minres * ((float)MINIMAP_RATIO / 100);
	data->minimap.square_size = data->minimap.size / minsize;
}