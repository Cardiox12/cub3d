/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:45:36 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/03 01:35:21 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include <stdio.h>
#include "render.h"
#include "colors.h"
#include "render.h"
#include <errno.h>

void	Debug_log_game(t_game *data, const char *path)
{
	printf("Map path : %s\n", path);
	printf("================================ TEXTURES : ================================\n");
	printf("North texture : %s\n", data->map.textures[IDX_NORTH].path);
	printf("South texture : %s\n", data->map.textures[IDX_SOUTH].path);
	printf("West texture : %s\n", data->map.textures[IDX_WEST].path);
	printf("East texture : %s\n", data->map.textures[IDX_EAST].path);
	printf("Sprite texture : %s\n", data->map.textures[IDX_SPRITE].path);
	printf("================================ RESOLUTION : ================================\n");
	printf("Resolution : %ix%i\n", data->map.resolution.x, data->map.resolution.y);
	printf("================================ COULEURS : ================================\n");
	printf("Floor color : %x\n", data->map.floor_color);
	printf("Ceil color : %x\n", data->map.ceil_color);
	printf("================================ MAP : ================================\n");
	printf("Map height : %i\n", data->map.map_ysize);
	printf("Map width : %i\n", data->map.map_xsize);
	for (int i =  0 ; data->map.map[i] != NULL ; i++)
		printf("%s\n", data->map.map[i]);
	
	for (int i = 0 ; i < data->map.sprites.cursor ; i++)
	{
		printf("Sprite :\n");
		printf("\tPos : (%f, %f)\n", data->map.sprites.sprites[i].pos.x, data->map.sprites.sprites[i].pos.y);
	}
}

static void	errexit(unsigned int errors, int listall)
{
	Errors_print(errors, listall);
	exit(1);
}

static int init(int argc, char **argv, t_game *data)
{
	int errors;
	
	errors = parse(data, argv[1]);
	if (errors)
	{
		exit(0);
	}
	if (argc > 2)
		cmd_parse(data, argv[2]);	
	if ((errors = init_game(data)))
		errexit(errors, TRUE);
	if ((errors = init_textures(data)))
		errexit(errors, TRUE);
	parse_sprites(data);
	if ((errors = init_sprite_variables(data)))
		errexit(errors, TRUE);
	if ((errors = init_game_image(data)))
		errexit(errors, TRUE);
	get_starting_point(data);
	return (RET_NO_ERROR);
}

int		main(int argc, char **argv)
{
	t_game data;
	
	if (argc > 1)
	{
		init(argc, argv, &data);
		mlx_hook(data.infos.win_ptr, KEY_PRESS_CODE, KEY_PRESS_MASK, key_pressed, &data);
		mlx_hook(data.infos.win_ptr, KEY_RELEASE_CODE, KEY_RELEASE_MASK, key_released, &data);
		mlx_hook(data.infos.win_ptr, STRUCTURE_NOTIFY_CODE, STRUCTURE_NOTIFY_MASK, exit_hook, &data);
		mlx_hook(data.infos.win_ptr, MOTION_NOTIFY_CODE, 0, motion_hook, &data);
		mlx_loop_hook(data.infos.mlx_ptr, loop, &data);
		mlx_loop(data.infos.mlx_ptr);
	}
	return (0);
}
