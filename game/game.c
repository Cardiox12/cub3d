/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:33:14 by bbellavi          #+#    #+#             */
/*   Updated: 2020/01/31 20:53:00 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdio.h>

static int  is_cardinal_point(char c)
{
    return (c == S_SOUTH || c == S_NORTH || c == S_EAST || c == S_WEST);
}

t_vec   *get_starting_coordinate(t_map *map)
{
    int     i;
    int     j;
    t_vec   *start_p;

    i = 0;
    j = 0;
    if (map != NULL)
    {
        if (map->map != NULL)
        {
            start_p = (t_vec*)malloc(sizeof(t_vec));
            if (start_p == NULL)
                return (NULL);
            while (map->map[i] != NULL)
            {
                while (map->map[i][j] != '\0')
                {
                    if (is_cardinal_point(map->map[i][j]))
                    {
                        start_p->x = j;
                        start_p->y = i;
                        return (start_p);
                    }
                    j++;
                }
                j = 0;
                i++;
            }
        }
    }
    return (NULL);
}

void    game(t_map *map)
{
    t_vec *start;

    start = get_starting_coordinate(map);
    printf("x : %i\n", start->x);
    printf("y : %i\n", start->y);
}