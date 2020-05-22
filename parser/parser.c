/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 17:39:44 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/22 23:30:07 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// Remove when final push
#include <stdio.h>

void		Debug_print_bits(unsigned int val)
{
	int index;

	index = sizeof(val) * 8;
	while (index >= 0)
	{
		--index;
		if (val & (1U << index))
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}

static int infos_parser(t_game *data, int fd)
{
	unsigned int	err;
	int				index;

	data->map.line = NULL;
	err = 0;
	while (get_next_line(fd, &data->map.line) > 0 && !is_mapline(data->map.line))
	{
		index = 0;
		while (index < ID_SIZE)
		{
			if (ft_strncmp(data->map.line, ids[index].id, ft_strlen(ids[index].id)) == 0)
			{
				err |= parse_callbacks[ids[index].index](data, ids[index].id, data->map.line);
				data->map.specs_number++;
				break;
			}
			index++;
		}
		freeline(data);
	}
	return ((err) ? err : RET_NO_ERROR);
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
	return (RET_NO_ERROR);
}

int		parse(t_game *data, const char *path)
{
	unsigned int errors;
	int	fd;

	errors = 0;
	if (has_valid_ext(path) == FALSE)
		return (ERROR);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ERROR);
	errors |= infos_parser(data, fd);
	errors |= map_parser(data, fd);
	map_processor(data);
	errors |= map_is_valid(data);
	close(fd);
	if (errors)
		print_errors(errors, TRUE);
	return (errors);
}