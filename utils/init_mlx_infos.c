/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_infos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 03:15:11 by bbellavi          #+#    #+#             */
/*   Updated: 2020/01/25 03:18:05 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* init t_mls_infos struct */

void    init_mlx_infos(t_mlx_infos *infos)
{
    if (infos != NULL)
    {
        infos->mlx_ptr = NULL;
        infos->win_ptr = NULL;
        infos->height = 0;
        infos->width = 0;
        infos->color = 0;
    }
}