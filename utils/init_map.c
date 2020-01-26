/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 03:04:14 by bbellavi          #+#    #+#             */
/*   Updated: 2020/01/26 03:10:20 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_map(t_map *map)
{
    if (map != NULL)
    {
        map->map = NULL;
        map->ceil_color = 0;
        map->ground_color = 0;
        init_textures(&map->textures);
        init_vec(&map->resolution);
    }
}