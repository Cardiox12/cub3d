/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:33:13 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 20:28:09 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

# include <stddef.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0
# define MINIMAP_RATIO 30
# define EXE_NAME "cub3d"
# define WINDOW_NAME "cub3d"
# define FIELD_OF_VIEW 66.0f
# define RAYS_NUMBER	10
# define TEX_NUMBERS	5
# define SPRITE_NUMBERS 1000
# define MAP_SIZE		20000
# define SPRITE '2'

typedef struct		s_infos
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				height;
	int				width;
	int				color;
}					t_infos;

typedef struct		s_pair
{
	double			val;
	int				index;
}					t_pair;

typedef struct		s_vec2
{
	float			x;
	float			y;
}					t_vec2;

typedef struct		s_vec
{
	int				x;
	int				y;
}					t_vec;

typedef struct		s_ray
{
	t_vec2			pos;
	t_vec2			dir;
	t_vec2			particle;
	float			angle;
}					t_ray;

typedef struct		s_image
{
	void			*img_ref;
	int				*img_data_addr;
	int				bits_per_pixel;
	int				line_size;
	int				endian;
	int				line_count;
}					t_image;

typedef struct		s_texture
{
	t_image			image;
	char			path[PATH_MAX + 1];
	int				width;
	int				height;
}					t_texture;

typedef struct		s_textures
{
	t_texture		north;
	t_texture		south;
	t_texture		west;
	t_texture		east;
	t_texture		sprite;
}					t_textures;

typedef struct		s_minmap
{
	unsigned int	size;
	unsigned int	square_size;
}					t_minimap;

typedef struct		s_sprite
{
	t_vec2			pos;
	int				texture;
	int				u_div;
	int				v_div;
	float			v_move;
}					t_sprite;

typedef struct		s_sprites
{
	t_sprite		sprites[SPRITE_NUMBERS];
	int				cursor;

	t_vec2			transform;
	t_vec			draw_start;
	t_vec			draw_end;
	t_vec			sprite_res;
	int				sprite_screen_x;
	t_vec			stripe;
	t_vec			tex;
	int				v_move_screen;
	double			inv_det;
	t_vec			tex_res;
	t_vec2			sprite;
}					t_sprites;

typedef struct		s_map
{
	char			*map[MAP_SIZE];
	t_vec			resolution;
	t_texture		textures[TEX_NUMBERS];
	t_sprites		sprites;
	unsigned int	floor_color;
	unsigned int	ceil_color;
	int				map_xsize;
	int				map_ysize;
	char			*line;
	unsigned int	specs_number;
	unsigned int	square_size;
}					t_map;

enum	e_cardinals_degree
{
	D_NORTH = 90,
	D_SOUTH = 270,
	D_EAST = 0,
	D_WEST = 180,
};

enum	e_cardinal_p
{
	S_NORTH = 'N',
	S_SOUTH = 'S',
	S_EAST = 'E',
	S_WEST = 'W'
};

typedef struct		s_camera
{
	int				side;
	int				hit;
	float			camera_angle;
	char			debug;
	float			wall_x;
	double			*zbuffer;
	int				*sprite_order;
	double			*sprite_distance;
	t_vec			tex;
	double			tex_step;
	double			tex_pos;
	t_vec2			pos;
	t_vec2			dir;
	t_vec2			plan_front;
	t_vec2			plan_right;
	t_vec2			plane;
	t_ray			rays[RAYS_NUMBER];
	float			field_of_view;
	t_vec2			ray_dir;
	double			camera_x;
	double			map_x;
	double			map_y;
	t_vec2			side_dist;
	double			perp_wall_dist;
	t_vec2			delta_dist;
	t_vec2			step;
	t_vec			map_pos;
	int				draw_start;
	int				draw_end;
	int				line_height;
}					t_camera;

typedef struct		s_game
{
	char			save;
	t_camera		camera;
	t_infos			infos;
	t_image			image;
	t_map			map;
	t_minimap		minimap;
}					t_game;

enum	e_facing
{
	DOWN,
	UP,
	RIGHT,
	LEFT
};

enum	e_texture_index
{
	IDX_NORTH,
	IDX_SOUTH,
	IDX_WEST,
	IDX_EAST,
	IDX_SPRITE
};

#endif
