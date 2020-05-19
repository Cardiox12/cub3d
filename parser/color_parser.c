/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 01:51:53 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/19 17:22:57 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <stdio.h>

int		parse_color(t_game *data, const char *id, char *line)
{	
	const size_t	id_len = ft_strlen(id);
	unsigned int	colors[RGB_SIZE];
	unsigned int	*color;
	int				index;

	index = 0;
	line = &line[id_len];
	ft_memset(colors, 0, sizeof(int) * RGB_SIZE);
	if (ft_strncmp(id, ID_CEIL, 1) == 0)
		color = &data->map.ceil_color;
	else
		color = &data->map.floor_color;
	line = skip_spaces(line);
	while (*line != '\0' && ft_isdigit(*line) && index < RGB_SIZE)
	{
		colors[index] = ft_atoi(line);
		// ERROR: value out of range
		if (colors[index] > 255)
			return (ERROR);
		line = skip_digits(line);
		line = skip_spaces(line);
		line = skip_char(line, COMMA);
		line = skip_spaces(line);
		index++;
	}
	// ERROR: inconsistent number of value, must be 3 value representing RGB
	if (*line != '\0' || index != RGB_SIZE)
		return (ERROR);
	*color = ft_encode_rgb(colors[0], colors[1], colors[2]);
	return (SUCCESS);
}