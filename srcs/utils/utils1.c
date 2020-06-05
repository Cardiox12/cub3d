/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:38:20 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 23:04:13 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "mlx.h"

int		max(int a, int b)
{
	return ((a > b) ? a : b);
}

int		min(int a, int b)
{
	return ((a < b) ? a : b);
}

void	check_screen_size(t_game *data)
{
	t_vec res;

	mlx_get_screen_size(data->infos.mlx_ptr, &res.x, &res.y);
	if (data->map.resolution.x > res.x)
		data->map.resolution.x = res.x;
	if (data->map.resolution.y > res.y)
		data->map.resolution.y = res.y;
}
