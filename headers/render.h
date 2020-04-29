/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:48:48 by bbellavi          #+#    #+#             */
/*   Updated: 2020/04/29 18:04:19 by bbellavi         ###   ########.fr       */
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

# define ANGLE_south 180
# define ANGLE_north 0
# define ANGLE_east 90
# define ANGLE_west 270

# define SQUARE_SIZE 40
# define WALL '1'
# define MAX_ANGLE 360
# define TRUE 1
# define FALSE 0


void	render(t_game *data);

void	draw_rect(t_vec pos, t_vec size, t_image *img, uint32_t color);
void	draw_img_vert_line(int x, int height, t_game *data, uint32_t color);
void	reset_img(t_game *data);
void	draw_ceil_and_floor(t_game *data);
void	draw_circle(t_vec pos, int radius, t_image *img, uint32_t color);
void	draw_img_line(t_vec a, t_vec b, t_game *data, uint32_t color);

int		is_cardinal_point(char c);
void	set_heading(t_camera *player, char cardinal_p);
void	get_side(t_game *data);
int		get_starting_point(t_game *data);


// Raycaster 2d
void    Ray_update(t_ray *ray, t_vec2 pos);
void    Ray_rotate(t_ray *ray, double theta, char clockwise);
void    Rays_update(t_ray *rays, t_vec2 pos);
void    Rays_rotate(t_ray *rays, double theta, char clockwise);

#endif