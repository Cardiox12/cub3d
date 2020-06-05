/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 01:52:30 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 22:55:40 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	check_res_errors(t_game *data, char *line)
{
	if (*line != '\0')
		return (CODE_ERR_BAD_CHARS_IN_RES_FIELD);
	if (data->map.resolution.x == 0 || data->map.resolution.y == 0)
		return (CODE_ERR_RESOLUTION_ZERO);
	return (RET_NO_ERROR);
}

int			parse_resolution(t_game *data, const char *id, char *line)
{
	const size_t	id_len = ft_strlen(id);
	int				i;
	int				*res;

	line = &line[id_len];
	res = &data->map.resolution.x;
	while (i < 2)
	{
		if (i == 1)
			res = &data->map.resolution.y;
		line = skip_spaces(line);
		if (*line == '\0')
			return (CODE_ERR_RES_MISSING_PARAM);
		if (ft_isdigit(*line))
		{
			*res = ft_atoi(line);
			while (*line != '\0' && ft_isdigit(*line))
				line++;
		}
		else
			return (CODE_ERR_BAD_CHARS_IN_RES_FIELD);
		i++;
	}
	return (check_res_errors(data, line));
}
