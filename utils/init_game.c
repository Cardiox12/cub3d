/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:14:39 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/27 12:18:18 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_string.h"

void	init_game_struct(t_game *data)
{
	if (data != NULL)
	{
		ft_memset(data->camera, 0, sizeof(t_camera));
		ft_memset(data->image, 0, sizeof(t_image));
		ft_memset(data->infos, 0, sizeof(t_mlx_infos));
		ft_memset(data->map, 0, sizeof(t_map));
	}
}