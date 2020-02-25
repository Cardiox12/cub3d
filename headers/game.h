/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:48:48 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/25 13:55:48 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef FT_GAME_H
#   define FT_GAME_H

#include <stdlib.h>
#include "cub3d.h"
#include "parser.h"
#include "utils.h"
#include "ft_string.h"
#include <math.h>

#   define CHUNK_SIZE 64
#   define WALL '1'
#   define MAX_ANGLE 360
#	define TRUE 1
#	define FALSE 0

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
	char	*img_data_addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}				t_image;


typedef struct	s_camera
{
	int side;
	int hit;
	int heading;

	// Position vector
	int posX;
	int posY;

	// Direction vector
	int dirX;
	int dirY;

	// Camera plan vector
	int planX;
	int planY;

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
	t_camera	*camera;
	t_mlx_infos	*infos;
	t_image		*image;
	t_map		*map;
}				t_game;

enum	e_facing
{
	DOWN,
	UP,
	RIGHT,
	LEFT
};

void	game(t_game *data);
void    init_player(t_camera *player);
void	draw_img_line(int x0, int y0, int x1, int y1, t_game *game);
void	draw_img_vert_line(int x, int height, int width, t_game *data);

#   endif