/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 01:51:53 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/22 23:35:18 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char *skip(char *line)
{
	line = skip_digits(line);
	line = skip_spaces(line);
	line = skip_char(line, COMMA);
	line = skip_spaces(line);
	return (line);
}

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
		if (colors[index] > 255)
			return (CODE_ERR_COLOR_OUT_OF_RANGE);
			line = skip(line);
		index++;
	}
	if (*line != '\0' || index != RGB_SIZE)
		return (CODE_ERR_COLOR_MISSING);
	*color = ft_encode_rgb(colors[0], colors[1], colors[2]);
	return (RET_NO_ERROR);
}