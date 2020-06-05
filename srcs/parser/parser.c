/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 17:39:44 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 22:30:59 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	check_id(t_game *data)
{
	unsigned int	err;
	int				i;

	err = 0;
	i = 0;
	while (i < ID_SIZE)
	{
		if (ft_strncmp(data->map.line, g_ids[i].id,
		ft_strlen(g_ids[i].id)) == 0)
		{
			err |= g_parse_callbacks[g_ids[i].index](data, g_ids[i].id,
			data->map.line);
			if (data->map.specs & g_ids[i].flag)
				err |= CODE_ERR_DUPLICATE_SPECS;
			data->map.specs |= g_ids[i].flag;
			break ;
		}
		else if (*data->map.line != '\0' && *data->map.line != SPACE
		&& !is_spec(data->map.line))
			err |= CODE_ERR_BAD_SPEC;
		i++;
	}
	return (err);
}

static int	infos_parser(t_game *data, int fd)
{
	unsigned int	err;

	err = 0;
	data->map.line = NULL;
	while (get_next_line(fd, &data->map.line) > 0 &&
	!is_mapline(data->map.line))
	{
		err |= check_id(data);
		freeline(data);
	}
	if (data->map.specs != SPECS_MAX)
		err |= CODE_ERR_INCONSISTENT_SPECS;
	return (err);
}

static int	get_line(t_game *data, int index)
{
	size_t maxlen;

	maxlen = ft_strlen(data->map.line);
	data->map.map[index] = ft_strdup(data->map.line);
	freeline(data);
	return (maxlen);
}

static int	map_parser(t_game *data, int fd)
{
	size_t maxlen;
	size_t index;

	index = 0;
	maxlen = 0;
	if (is_mapline(data->map.line))
		maxlen = max(maxlen, get_line(data, index++));
	while (get_next_line(fd, &data->map.line) > 0 && is_mapline(data->map.line))
		maxlen = max(maxlen, get_line(data, index++));
	if (is_mapline(data->map.line))
		maxlen = max(maxlen, get_line(data, index++));
	else if (contains_mapchar(data->map.line))
		get_line(data, index++);
	data->map.map_ysize = index;
	data->map.map_xsize = maxlen;
	data->map.map[index] = NULL;
	return (RET_NO_ERROR);
}

int			parse(t_game *data, const char *path)
{
	unsigned int	errors;
	int				fd;

	errors = 0;
	data->map.specs = 0;
	if (has_valid_ext(path) == FALSE)
		return (errors_print(CODE_ERR_BAD_FILE_EXT, FALSE));
	if ((fd = open(path, O_RDONLY)) < 0)
		error_std(EXE_NAME);
	errors |= infos_parser(data, fd);
	if (errors & CODE_ERR_INCONSISTENT_SPECS)
	{
		close(fd);
		return (errors);
	}
	errors |= map_parser(data, fd);
	if ((errors |= map_processor(data)))
		return (errors);
	errors |= check_eof(data, fd);
	errors |= map_is_valid(data);
	close(fd);
	return (errors);
}
