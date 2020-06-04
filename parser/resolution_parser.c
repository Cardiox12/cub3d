/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 01:52:30 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/04 04:05:38 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_resolution(t_game *data, const char *id, char *line)
{
	const size_t id_len = ft_strlen(id);

	line = &line[id_len];
	line = skip_spaces(line);
	if (*line == '\0')
		return (CODE_ERR_RES_MISSING_PARAM);
	if (ft_isdigit(*line))
	{
		data->map.resolution.x = ft_atoi(line);
		while (*line != '\0' && ft_isdigit(*line))
			line++;
	}
	else
		return (CODE_ERR_BAD_CHARS_IN_RES_FIELD);
	line = skip_spaces(line);
	if (*line == '\0')
		return (CODE_ERR_RES_MISSING_PARAM);
	if (ft_isdigit(*line))
	{
		data->map.resolution.y = ft_atoi(line);
		while (*line != '\0' && ft_isdigit(*line))
			line++;
	}
	else
		return (CODE_ERR_BAD_CHARS_IN_RES_FIELD);
	if (*line != '\0')
		return (CODE_ERR_BAD_CHARS_IN_RES_FIELD);
	if (data->map.resolution.x == 0 || data->map.resolution.y == 0)
		return (CODE_ERR_RESOLUTION_ZERO);
	return (RET_NO_ERROR);
}