/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:33:13 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/18 18:40:46 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

#include <stddef.h>

# define RAYS_NUMBER 10
# define TEX_NUMBERS 5

typedef struct  s_infos
{
    void    *mlx_ptr;
    void    *win_ptr;
    int     height;
    int     width;
    int     color;
}               t_infos;

typedef struct	s_vec2
{
	float		x;
	float		y;
}				t_vec2;

typedef struct  s_vec
{
    int x;
    int y;
}               t_vec;

typedef struct	s_ray
{
	t_vec2 	pos;
	t_vec2 	dir;
	t_vec2 	particle;
	float	angle;
}				t_ray;

typedef struct	s_image
{
	void	*img_ref;
	int		*img_data_addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
	int		line_count;
}				t_image;

typedef struct	s_texture
{
	t_image image;
	char	*path;
	int		width;
	int		height;
}				t_texture;

typedef struct  s_textures
{
    t_texture	north;
    t_texture	south;
    t_texture	west;
    t_texture	east;
    t_texture	sprite;
}               t_textures;

typedef struct  s_map
{
    char        **map;
    t_vec       resolution;
    t_texture	textures[TEX_NUMBERS];
    int         ground_color;
    int         ceil_color;
    int         map_xsize;
    int         map_ysize;
}               t_map;

typedef struct	s_list
{
	void			*ptr;
	struct s_list	*next;
}				t_list;

typedef enum    e_cardinals_degree
{
    D_NORTH = 90,
    D_SOUTH = 270,
    D_EAST = 0,
    D_WEST = 180,
}               t_cardinals_degree;

typedef enum    e_cardinal_p
{
	S_NORTH		= 'N',
	S_SOUTH		= 'S',
	S_EAST		= 'E',
	S_WEST		= 'W'
}               e_cardinal_p;

typedef struct	s_camera
{
	int		side;
	int		hit;
	float	camera_angle;
	char	debug;
	float	wallX;

	// Texture coordinates
	t_vec tex;
	double tex_step;
	double tex_pos;

	// Position vector
	t_vec2 pos;

	// Direction vector
	t_vec2 dir;

	// Camera plan vector
	t_vec2 plan_front;
	t_vec2 plan_right;
	t_vec2 plane;

	// fov
	t_ray rays[RAYS_NUMBER];
	float field_of_view;

	// Deltas
	t_vec2 ray_dir;

	// Camera
	double cameraX;

	// Other map variable
	double mapX;
	double mapY;

	// Side distance
	t_vec2	side_dist;

	// Distances
	double perp_wall_dist;

	// Deltas distance
	t_vec2 delta_dist;

	// Steps
	t_vec2 step;

	// Distance from the wall
	double wallDist;


	// Map post
	t_vec map_pos;

	// Draw wall variables
	int draw_start;
	int draw_end;
	int line_height;
}				t_camera;

typedef struct	s_game
{
	t_camera	camera;
	t_infos		infos;
	t_image		image;
	t_map		map;
}				t_game;

enum	e_facing
{
	DOWN,
	UP,
	RIGHT,
	LEFT
};

# define CLOCKWISE 1
# define ANTI_CLOCKWISE 0

# define TRUE 1
# define FALSE 0

#endif