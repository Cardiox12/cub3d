/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 12:53:43 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/24 16:32:15 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void    init_player(t_player *player)
{
    if (player != NULL)
    {
		ft_memset(player, 0, sizeof(t_player));
    }
}