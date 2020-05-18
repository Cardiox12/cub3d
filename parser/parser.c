/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 17:39:44 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/18 23:50:21 by bbellavi         ###   ########.fr       */
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

void	parse_texture(t_game *data, const char *id)
{
	(void)data;
	(void)id;
}

void	parse_color(t_game *data, const char *id)
{
	(void)data;
	(void)id;
}

void	parse_resolution(t_game *data, const char *id)
{
	(void)data;
	(void)id;
}

int		parse(t_game *data, const char *path)
{
	int		index;
	char	*line;
	int		fd;

	line = NULL;
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
				parse_callbacks[ids[index].index](data, line);
				break;
			}
			index++;
		}
	}
	return (TRUE);
}