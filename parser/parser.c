/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 17:39:44 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/20 17:54:01 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// Remove when final push
#include <stdio.h>

int		has_valid_ext(const char *path)
{
	const size_t len = ft_strlen(path);
	const size_t ext_len = ft_strlen(MAP_EXT);

	if (len < 5)
		return (FALSE);
	if (ft_strncmp(&path[len - ext_len], MAP_EXT, ext_len) != 0)
		return (FALSE);
	return (TRUE);
}

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
}

int		parse(t_game *data, const char *path)
{
	int		err;
	int		index;
	char	*line;
	int		fd;

	line = NULL;
	err = ERROR;
	if (has_valid_ext(path) == FALSE)
		return (ERROR);

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ERROR);

	while (get_next_line(fd, &line) > 0)
	{
		index = 0;
		while (index < ID_SIZE)
		{
			if (ft_strncmp(line, ids[index].id, ft_strlen(ids[index].id)) == 0)
			{
				err = parse_callbacks[ids[index].index](data, ids[index].id, line);
				if (err < 0)
					return (err);
				break;
			}
			index++;
		}
	}
	Debug_log_game(data, path);
	close(fd);
	return (err);
}