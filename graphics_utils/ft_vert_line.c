/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vert_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:15:13 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/25 14:55:29 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics_utils.h"

void	vertical_line(int x, int height, int width, t_mlx_infos *infos)
{
	line(x, height, x, width, infos);
}
