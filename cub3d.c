/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:45:36 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 14:36:32 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include "render.h"
#include "render.h"
#include <errno.h>

static void	errexit(t_game *data, unsigned int errors, int listall)
{
	free_game(data);
	Errors_print(errors, listall);
	exit(1);
}

static int	init(int argc, char **argv, t_game *data)
{
	int errors;

	ft_memset(data, 0, sizeof(t_game));
	data->save = FALSE;
	errors = parse(data, argv[1]);
	if (errors)
		errexit(data, errors, TRUE);
	if (argc > 2)
	{
		if ((errors = cmd_parse(data, argv[2])))
			errexit(data, errors, TRUE);
	}
	if ((errors = init_game(data)))
		errexit(data, errors, TRUE);
	parse_sprites(data);
	if ((errors = init_sprite_variables(data)))
		errexit(data, errors, TRUE);
	if ((errors = init_game_image(data)))
		errexit(data, errors, TRUE);
	get_starting_point(data);
	return (RET_NO_ERROR);
}

int			main(int argc, char **argv)
{
	t_game data;

	if (argc > 1)
	{
		init(argc, argv, &data);
		if (data.save == FALSE)
		{
			mlx_hook(data.infos.win_ptr, KEY_PRESS_CODE, KEY_PRESS_MASK,
			key_pressed, &data);
			mlx_hook(data.infos.win_ptr, KEY_RELEASE_CODE, KEY_RELEASE_MASK,
			key_released, &data);
			mlx_hook(data.infos.win_ptr, STRUCTURE_NOTIFY_CODE,
			STRUCTURE_NOTIFY_MASK, exit_hook, &data);
			mlx_hook(data.infos.win_ptr, MOTION_NOTIFY_CODE, 0,
			motion_hook, &data);
		}
		mlx_loop_hook(data.infos.mlx_ptr, loop, &data);
		mlx_loop(data.infos.mlx_ptr);
	}
	return (0);
}
