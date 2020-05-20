/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 22:39:22 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/21 00:18:18 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
	- POUR TOUT ligne dans MAP : 
		- si taille de ligne < maxlen :
			- resize ligne avec maxlen
		- POUR TOUT i ALLANT de 0 -> maxlen :
			- si ligne[i] est un espace :
				- ligne[i] = VIDE

*/

#include <stdio.h>

void	map_processor(t_game *data)
{
	size_t	curlen;
	t_vec	i;

	i.y = 0;
	while (i.y < data->map.map_ysize)
	{
		curlen = ft_strlen(data->map.map[i.y]);
		if (curlen < (size_t)data->map.map_xsize)
		{
			data->map.map[i.y] = ft_realloc(data->map.map[i.y], curlen, data->map.map_xsize + 1);
			// i.x = 0;
			// while (i.x)
		}
		i.x = 0;
		while (i.x < data->map.map_xsize)
		{
			if (data->map.map[i.y][i.x] == SPACE || data->map.map[i.y][i.x] == '\0')
			{
				data->map.map[i.y][i.x] = EMPTY;
			}
			i.x++;
		}
		i.y++;
	}
}