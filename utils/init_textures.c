/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 03:06:24 by bbellavi          #+#    #+#             */
/*   Updated: 2020/01/26 03:07:54 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_textures(t_textures *textures)
{
    if (textures != NULL)
    {
        textures->north = NULL;
        textures->south = NULL;
        textures->east = NULL;
        textures->west = NULL;
        textures->sprite = NULL;
    }
}