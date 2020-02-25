/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:45:36 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/25 16:23:05 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include <stdio.h>
#include "game.h"


int		main(int argc, __unused char **argv)
{
	t_game		data;
	t_camera	camera;
	t_map		map;
	t_vec		vec;
	t_textures	textures;
	t_mlx_infos	infos;
	t_image		image;

	if (argc > 1)
	{
		map.resolution = &vec;
		map.textures = &textures;
		init_map(&map);
		init_mlx_infos(&infos);
		infos.height = 1000;
		infos.width = 1000;
		data.camera = &camera;
		data.map = &map;
		data.image = &image;
		infos.mlx_ptr = mlx_init();
		infos.win_ptr = mlx_new_window(infos.mlx_ptr, infos.width, infos.height, "cub3d");
		data.infos = &infos;
		data.image->img_ref = mlx_new_image(data.infos->mlx_ptr, data.infos->width, data.infos->height);
		data.image->img_data_addr = mlx_get_data_addr(
		data.image->img_ref,
		&data.image->bits_per_pixel,
		&data.image->line_size,
		&data.image->endian);

		parse_map(argv[1], &map);
		game(&data);
		mlx_loop(infos.mlx_ptr);
	}
}
