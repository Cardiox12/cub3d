/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:14:03 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/19 15:50:05 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef FT_LIBGL_H
#   define FT_LIBGL_H

#include "cub3d.h"

void	rect(int x, int y, int w, int h, t_mlx_infos *infos);
void    line(int x1, int y1, int x2, int y2, t_mlx_infos *infos);
int		ft_encode_rgb(unsigned char red, unsigned char green, unsigned char blue);

#   endif