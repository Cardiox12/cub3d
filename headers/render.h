/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:48:48 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 21:50:55 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RENDER_H
# define FT_RENDER_H

# include <math.h>
# include <stdlib.h>
# include <inttypes.h>
# include "parser.h"
# include "utils.h"
# include "ft_string.h"
# include "graphics_utils.h"
# include "types.h"
# include "vectors.h"

# define ANGLE_SOUTH 180
# define ANGLE_NORTH 0
# define ANGLE_EAST 90
# define ANGLE_WEST 270

# define SQUARE_SIZE 20
# define WALL '1'
# define MAX_ANGLE 360
# define TRUE 1
# define FALSE 0

void		render(t_game *data);

void		draw_rect(t_vec pos, t_vec size, t_image *img, uint32_t color);
void		draw_img_vert_line(int x, t_vec draw, t_game *data, uint32_t color);
void		reset_img(t_game *data);
void		draw_ceil_and_floor(t_game *data);
void		draw_circle(t_vec pos, int radius, t_image *img, uint32_t color);
void		draw_img_line(t_vec a, t_vec b, t_game *data, uint32_t color);
void		set_color(t_game *data, t_vec pos, int color);
uint32_t	get_color(t_image *img, t_vec pos, int w);

int			is_cardinal_point(char c);
void		set_heading(t_camera *player, char cardinal_p);
void		get_side(t_game *data);
int			get_starting_point(t_game *data);

void		ray_update(t_ray *ray, t_vec2 pos);
void		ray_rotate(t_ray *ray, double theta, char clockwise);
void		rays_update(t_ray *rays, t_vec2 pos);
void		rays_rotate(t_ray *rays, double theta, char clockwise);

void		player_move_down(t_game *data);
void		player_move_up(t_game *data);
void		player_move_left(t_game *data);
void		player_move_right(t_game *data);
void		player_rotate(t_game *data);

int			is_out_of_bound(t_vec2 pos, t_game *data);

void		draw_plan(t_game *data, t_vec2 cp);
void		minimap_raycaster(t_game *data, t_vec2 pos);
void		minimap(t_game *data);
void		raycasting(t_game *data);

int			init_textures(t_game *data);
int			init_game(t_game *data);
int			init_game_image(t_game *data);
int			init_sprite_variables(t_game *data);
void		cast_sprites(t_game *data);
void		sort_sprites_dist(t_game *data);

void		get_side(t_game *data);
int			texture_choser(t_game *data);
void		map_texture(t_game *data, int x);

#endif
