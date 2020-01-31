/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:45:36 by bbellavi          #+#    #+#             */
/*   Updated: 2020/01/31 20:52:19 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include <stdio.h>
#include "game.h"

int		main(int argc, char **argv)
{
    t_map       map;
    t_vec       vec;
    t_textures  textures;

    map.resolution = &vec;
    map.textures = &textures;
    init_map(&map);
    if (argc > 1)
    {
        parse_map(argv[1], &map);
        game(&map);
    }
}
