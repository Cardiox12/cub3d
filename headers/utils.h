/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 03:18:15 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/27 12:09:21 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef FT_UTILS_H
#   define FT_UTILS_H

#include "cub3d.h"

void    init_mlx_infos(t_mlx_infos *infos);
void    init_textures(t_textures *textures);
void    init_vec(t_vec *vec);
void    init_map(t_map *map);
t_list	*lst_create(void *ptr);
t_list	*lst_add(t_list **origin, void *ptr);

#   endif