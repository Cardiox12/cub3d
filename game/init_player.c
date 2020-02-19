/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 12:53:43 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/01 12:54:48 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void    init_player(t_player *player)
{
    if (player != NULL)
    {
        player->curr_x = 0;
        player->curr_y = 0;
        player->heading = 0;
    }
}