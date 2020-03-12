/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:48:48 by bbellavi          #+#    #+#             */
/*   Updated: 2020/03/12 18:30:57 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef FT_RENDER_H
#   define FT_RENDER_H

#include <math.h>
#include <stdlib.h>
#include <inttypes.h>
#include "parser.h"
#include "utils.h"
#include "ft_string.h"
#include "graphics_utils.h"
#include "types.h"

# define SQUARE_SIZE 40
# define WALL '1'
# define MAX_ANGLE 360
# define TRUE 1
# define FALSE 0


void	draw_rect(t_vec pos, t_vec size, t_image *img, uint32_t color);
void	render(t_game *data);
void	draw_img_line(t_vec a, t_vec b, t_game *data);
void	draw_img_vert_line(int x, int height, t_game *data);
void	reset_img(t_game *data);
void	draw_img_rect(t_rect *rect);
void	draw_ceil_and_floor(t_game *data);
void	draw_circle(t_vec pos, int radius, t_image *img, uint32_t color);


#endif