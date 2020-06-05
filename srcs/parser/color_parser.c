/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 01:51:53 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 22:02:47 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*skip(char *line)
{
	line = skip_digits(line);
	line = skip_spaces(line);
	line = skip_char(line, COMMA);
	line = skip_spaces(line);
	return (line);
}

static void	get_color_ptr(t_game *data, const char *id, unsigned int **color)
{
	if (ft_strncmp(id, ID_CEIL, 1) == 0)
		*color = &data->map.ceil_color;
	else
		*color = &data->map.floor_color;
}

int			parse_color(t_game *data, const char *id, char *line)
{
	const size_t	id_len = ft_strlen(id);
	unsigned int	*color;
	int				colors[RGB_SIZE];
	int				index;

	index = 0;
	line = &line[id_len];
	get_color_ptr(data, id, &color);
	ft_memset(colors, 0, sizeof(int) * RGB_SIZE);
	line = skip_spaces(line);
	while (*line != '\0' && ft_isdigit(*line) && index < RGB_SIZE)
	{
		colors[index] = ft_atoi(line);
		if (colors[index] > 255 || colors[index] < 0)
			return (CODE_ERR_COLOR_OUT_OF_RANGE);
		line = skip(line);
		index++;
	}
	if (*line != '\0')
		return (CODE_ERR_BAD_CHARS_IN_COLORS);
	if (index != RGB_SIZE)
		return (CODE_ERR_COLOR_MISSING);
	*color = ft_encode_rgb(colors[0], colors[1], colors[2]);
	return (RET_NO_ERROR);
}
