/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 22:02:13 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 22:08:54 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	freeline(t_game *data)
{
	free(data->map.line);
	data->map.line = NULL;
}

int		is_mapline(const char *line)
{
	int		index;
	char	*local_line;

	index = 0;
	if (line == NULL || *line == '\0')
		return (FALSE);
	local_line = skip_spaces(line);
	if (*local_line == '\0')
		return (FALSE);
	while (local_line[index] != '\0')
	{
		if (ft_strchr(MAP_CHARSET_EXTEND, local_line[index]) == NULL)
			return (FALSE);
		index++;
	}
	return (TRUE);
}

int		is_spec(const char *id)
{
	int idlen;
	int index;

	index = 0;
	while (index < ID_SIZE)
	{
		idlen = ft_strlen(g_ids[index].id);
		if (ft_strncmp(g_ids[index].id, id, idlen) == 0)
			return (TRUE);
		index++;
	}
	return (FALSE);
}

int		contains_mapchar(const char *line)
{
	if (line == NULL)
		return (FALSE);
	while (*line != '\0')
	{
		if (ft_strchr(MAP_CHARSET_EXTEND, *line))
			return (TRUE);
		line++;
	}
	return (FALSE);
}
