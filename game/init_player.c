/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 12:53:43 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/25 08:10:32 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void    init_player(t_camera *player)
{
    if (player != NULL)
    {
		ft_memset(player, 0, sizeof(t_camera));
    }
}