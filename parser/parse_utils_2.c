/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 22:02:13 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/20 22:08:05 by bbellavi         ###   ########.fr       */
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
	if (line == NULL || *line == '\0')
		return (FALSE);
	while (*line != '\0')
	{
		if (ft_strchr(MAP_CHARSET, *line) == NULL)
			return (FALSE);
		line++;
	}
	return (TRUE);
}