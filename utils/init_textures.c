/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:23:18 by bbellavi          #+#    #+#             */
/*   Updated: 2020/01/29 22:23:38 by bbellavi         ###   ########.fr       */
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