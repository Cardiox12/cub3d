/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 22:02:13 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/25 07:27:05 by bbellavi         ###   ########.fr       */
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
	int		counter;
	char	*final_line;

	if (line == NULL || *line == '\0')
		return (FALSE);
	final_line = (char*)line;
	counter = 0;
	while (*line != '\0')
	{
		if (*line == SPACE)
			counter++;
		else if (ft_strchr(MAP_CHARSET, *line) == NULL)
			return (FALSE);
		line++;
	}
	if (counter == (line - final_line))
		return (FALSE);
	return (TRUE);
}

int		is_spec(const char *id)
{
	int idlen;
	int index;
	
	index = 0;
	while (index < ID_SIZE)
	{
		idlen = ft_strlen(ids[index].id);
		if (ft_strncmp(ids[index].id, id, idlen) == 0)
			return (TRUE);
		index++;
	}
	return (FALSE);
}