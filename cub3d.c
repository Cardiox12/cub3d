/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:45:36 by bbellavi          #+#    #+#             */
/*   Updated: 2020/03/02 10:19:06 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include <stdio.h>
#include "game.h"
#include "colors.h"
#define WINDOW_NAME "cub3d"
#define WINDOW_HEIGHT 1080
#define WINDOW_WIDTH 1920

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

void	init_game(t_game *data, int width, int height)
{
	fill_data1(data);
	fill_data2(data);
	data->infos->mlx_ptr = mlx_init();
	data->infos->win_ptr = mlx_new_window(
		data->infos->mlx_ptr,
		width,
		height,
		WINDOW_NAME);
}

#include <string.h>
#define MAP_HEIGHT 7
#define MAP_WIDTH 20

void	fill_map(t_map *map, char **map_str)
{
	map->ceil_color = BLUE_SKY;
	map->ground_color = BROWN;
	map->map_xsize = MAP_WIDTH;
	map->map_ysize = MAP_HEIGHT;
	map->resolution->x = 1920;
	map->resolution->x = 1080;
	map->map = map_str;
}

char	**init_map_array()
{
	char **map = (char**)malloc(sizeof(char*) * MAP_HEIGHT + 1);
	
	for (int i = 0 ; i < MAP_HEIGHT ; i++)
		map[i] = (char*)malloc(sizeof(char) * (MAP_WIDTH + 1));
	
	strcpy(map[0], "1111111111111111111");
	strcpy(map[1], "1000000000000000001");
	strcpy(map[2], "1000000000000000001");
	strcpy(map[3], "1000000000000000001");
	strcpy(map[4], "1000000000000000001");
	strcpy(map[5], "1111111111111111111");
	map[6] = NULL;
	return (map);
}

int		main(int argc, char **argv)
{
	(void)argv;
	t_game data;

	if (argc > 1)
	{
		init_game(&data, WINDOW_WIDTH, WINDOW_HEIGHT);
		data.image->img_ref = mlx_new_image(data.infos->mlx_ptr, data.infos->width, data.infos->height);
		data.image->img_data_addr = mlx_get_data_addr(data.image->img_ref, &data.image->bits_per_pixel, &data.image->line_size, &data.image->endian);
		// parse_map(argv[1], data.map);`
		// fill_map(data.map, init_map_array());
		// game(&data);
		// mlx_key_hook(data.infos->win_ptr, keyboard_hook, NULL);
		mlx_loop(data.infos->mlx_ptr);
	}
}
