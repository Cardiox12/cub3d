/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:45:36 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/27 13:53:26 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include <stdio.h>
#include "game.h"
#define WINDOW_NAME "cub3d"

void	fill_data2(t_game *data)
{
	static t_textures	textures;
	static t_vec		vec;

	init_vec(&vec);
	init_textures(&textures);
	data->map->resolution = &vec;
	data->map->textures = &textures;
}

void	fill_data1(t_game *data)
{
	static t_map		map;
	static t_camera		camera;
	static t_mlx_infos	infos;
	static t_image		image;

	init_mlx_infos(&infos);
	init_map(&map);
	data->map = &map;
	data->camera = &camera;
	data->infos = &infos;
	data->image = &image;
}

void	init_game(t_game *data)
{
	fill_data1(data);
	fill_data2(data);
	data->infos->mlx_ptr = mlx_init();
	data->infos->win_ptr = mlx_new_window(
		data->infos->mlx_ptr,
		data->map->resolution->x,
		data->map->resolution->y, 
		WINDOW_NAME);
}

int		main(int argc, char **argv)
{
	t_game data;

	if (argc > 1)
	{
		init_game(&data);
		data.image->img_ref = mlx_new_image(data.infos->mlx_ptr, data.infos->width, data.infos->height);
		data.image->img_data_addr = mlx_get_data_addr(data.image->img_ref, &data.image->bits_per_pixel, &data.image->line_size, &data.image->endian);
		parse_map(argv[1], data.map);
		game(&data);
		mlx_loop(data.infos->mlx_ptr);
	}
}
