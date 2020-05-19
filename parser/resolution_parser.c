/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 01:52:30 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/19 02:22:08 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_resolution(t_game *data, const char *id, char *line)
{
	const size_t id_len = ft_strlen(id);

	line = &line[id_len];
	line = skip_spaces(line);
	if (ft_isdigit(*line))
	{
		data->map.resolution.x = ft_atoi(line);
		while (*line != '\0' && ft_isdigit(*line))
			line++;
	}
	else
		return (ERROR);
	line = skip_spaces(line);
	if (ft_isdigit(*line))
	{
		data->map.resolution.y = ft_atoi(line);
		while (*line != '\0' && ft_isdigit(*line))
			line++;
	}
	else
		return (ERROR);
	return (0);
}