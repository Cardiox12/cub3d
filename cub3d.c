/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:45:36 by bbellavi          #+#    #+#             */
/*   Updated: 2020/03/03 13:43:00 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include <stdio.h>
#include "render.h"
#include "colors.h"
#define WINDOW_NAME "cub3d"
#define WINDOW_HEIGHT 1080
#define WINDOW_WIDTH 1920



void	init_game(t_game *data)
{
	data->map.resolution.x = WINDOW_WIDTH;
	data->map.resolution.y = WINDOW_HEIGHT;
	data->infos.mlx_ptr = mlx_init();
	data->infos.win_ptr = mlx_new_window(
		data->infos.mlx_ptr,
		data->map.resolution.x,
		data->map.resolution.y,
		WINDOW_NAME
	);
	data->map.ceil_color = COLOR_CEIL;
	data->map.ground_color = COLOR_FLOOR;
}

int		main(int argc, char __unused **argv)
{
	t_game data;
	
	if (argc > 1)
	{
		init_game(&data);
		parse_map(argv[1], &data.map);
		render(&data);
		mlx_key_hook(data.infos.win_ptr, keyboard_hook, NULL);
		mlx_loop(data.infos.mlx_ptr);
	}
}