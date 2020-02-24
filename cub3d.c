/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:45:36 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/24 17:44:13 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include <stdio.h>
#include "game.h"

int		main(int argc, __unused char **argv)
{
	t_map		map;
	t_vec		vec;
	t_textures	textures;
	t_mlx_infos	infos;

	map.resolution = &vec;
	map.textures = &textures;
	init_map(&map);
	init_mlx_infos(&infos);
	infos.height = 1000;
	infos.width = 1000;
	if (argc > 1)
	{
		infos.mlx_ptr = mlx_init();
		infos.win_ptr = mlx_new_window(infos.mlx_ptr, infos.width, infos.height, "cub3d");
		parse_map(argv[1], &map);
		game(&map, &infos);
		mlx_loop(infos.mlx_ptr);
	}
}
