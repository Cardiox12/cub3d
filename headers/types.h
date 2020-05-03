/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:33:13 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/03 16:13:51 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

#include <stddef.h>

# define RAYS_NUMBER 10

typedef struct  s_mlx_infos
{
    void    *mlx_ptr;
    void    *win_ptr;
    int     height;
    int     width;
    int     color;
}               t_mlx_infos;

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

typedef struct  s_textures
{
    char *north;
    char *south;
    char *west;
    char *east;
    char *sprite;
}               t_textures;

typedef struct  s_map
{
    char        **map;
    t_vec       resolution;
    t_textures  *textures;
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

typedef struct	s_image
{
	void	*img_ref;
	int		*img_data_addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
	int		line_count;
}				t_image;


typedef struct	s_camera
{
	int side;
	int hit;
	float camera_angle;
	char debug;

	// Position vector
	t_vec2 pos;
	// float posX;
	// float posY;

	// Direction vector
	int dirX;
	int dirY;

	// Camera plan vector
	t_vec2 plan_front;
	t_vec2 plan_right;
	// double planX;
	// double planY;

	// fov
	t_ray rays[RAYS_NUMBER];
	float field_of_view;

	// Deltas
	double rayDirX;
	double rayDirY;

	// Camera
	double cameraX;

	// Other map variable
	double mapX;
	double mapY;

	// Side distance
	double sideDistX;
	double sideDistY;

	// Deltas distance
	double deltaDistX;
	double deltaDistY;

	// Steps
	double stepX;
	double stepY;

	// Distance from the wall
	double wallDist;

	// Draw wall variables
	int drawStart;
	int drawEnd;
	int lineHeight;
}				t_camera;

typedef struct	s_game
{
	t_camera	camera;
	t_mlx_infos	infos;
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

typedef struct	s_rect
{
	t_game 	*game;
	int		height;
	int		width;
	int		x;
	int		y;
	int		color;
}				t_rect;

# define TRUE 1
# define FALSE 0
# define CLOCKWISE 1
# define ANTI_CLOCKWISE 0

#endif