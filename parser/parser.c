/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 17:39:44 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/20 22:08:56 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// Remove when final push
#include <stdio.h>

static int infos_parser(t_game *data, int fd)
{
	int		index;
	int		err;

	data->map.line = NULL;
	while (get_next_line(fd, &data->map.line) > 0 && !is_mapline(data->map.line))
	{
		index = 0;
		while (index < ID_SIZE)
		{
			if (ft_strncmp(data->map.line, ids[index].id, ft_strlen(ids[index].id)) == 0)
			{
				err = parse_callbacks[ids[index].index](data, ids[index].id, data->map.line);
				if (err < 0)
					return (err);
				break;
			}
			index++;
		}
		freeline(data);
	}
	return (SUCCESS);
}

static int map_parser(t_game *data, int fd)
{
	size_t maxlen;
	size_t index;

	index = 0;
	if (is_mapline(data->map.line))
	{
		maxlen = ft_strlen(data->map.line);
		data->map.map[index++] = ft_strdup(data->map.line);
		freeline(data);
	}
	while (get_next_line(fd, &data->map.line) > 0 || is_mapline(data->map.line))
	{
		maxlen = max(maxlen, ft_strlen(data->map.line));
		data->map.map[index++] = ft_strdup(data->map.line);
		freeline(data);
	}
	data->map.map_ysize = index;
	data->map.map_xsize = maxlen;
	data->map.map[index] = NULL;
	return (SUCCESS);
}

int		parse(t_game *data, const char *path)
{
	t_vec err;
	int	fd;

	if (has_valid_ext(path) == FALSE)
		return (ERROR);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ERROR);
	err.x = infos_parser(data, fd);
	err.y = map_parser(data, fd);
	close(fd);
	return ((err.x == ERROR || err.y == ERROR) ? ERROR : SUCCESS);
}