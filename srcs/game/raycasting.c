/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 23:14:30 by tony              #+#    #+#             */
/*   Updated: 2020/06/02 23:29:36 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "render.h"

// MARK: To remove
#include <stdio.h>

static int	texture_choser(t_game *data)
{
	const int angle = vector_angle(data->camera.ray_dir);
	
	if (data->camera.side == 1 && (angle >= 0 && angle < 180))
		return (IDX_NORTH);
	if (data->camera.side == 1 && (angle >= 180 && angle <= 360))
		return (IDX_SOUTH);
	if (data->camera.side == 0 && (angle > 90 && angle < 270))
		return (IDX_EAST);
	if (data->camera.side == 0 && ((angle >= 270 && angle <= 360) || (angle >= 0 && angle <= 90)))
		return (IDX_WEST);
	return (IDX_NORTH);
}

int		sort_sprites(int *order, double *dist, int amount)
{
	t_pair *pairs;
	int i;

	i = 0;
	pairs = malloc(sizeof(t_pair) * amount);
	if (pairs == NULL)
		return (RET_ERROR);
	while (i < amount)
	{
		pairs[i].val = dist[i];
		pairs[i].index = order[i];
		i++;
	}
	sort_pairs(pairs, amount);
	i = 0;
	while (i < amount)
	{
		dist[i] = pairs[i].val;
		order[i] = pairs[i].index;
		i++;
	}
	free(pairs);
	return (RET_NO_ERROR);
}

void	cast_sprites(t_game *data)
{
	t_vec2	sprite;
	t_vec2	transform;
	t_vec	draw_start;
	t_vec	draw_end;
	t_vec	sprite_res;
	const double	inv_det = 1.0 / (data->camera.plan_right.x * data->camera.plan_front.y - data->camera.plan_front.x * data->camera.plan_right.y);
	int		sprite_screen_x;
	int		i;
	t_vec	stripe;
	t_vec	tex;
	const t_vec	tex_res = (t_vec){data->map.textures[IDX_SPRITE].width, data->map.textures[IDX_SPRITE].height};
	int		v_move_screen;

	i = 0;
	while (i < data->map.sprites.cursor)
	{
		data->camera.sprite_order[i] = i;
		data->camera.sprite_distance[i] = (pow(data->camera.pos.x - data->map.sprites.sprites[i].pos.x, 2) + pow(data->camera.pos.y - data->map.sprites.sprites[i].pos.y, 2));
		i++;
	}
	sort_sprites(data->camera.sprite_order, data->camera.sprite_distance, data->map.sprites.cursor);
	i = 0;
	while (i < data->map.sprites.cursor)
	{
		sprite = (t_vec2){
			data->map.sprites.sprites[data->camera.sprite_order[i]].pos.x - data->camera.pos.x,
			data->map.sprites.sprites[data->camera.sprite_order[i]].pos.y - data->camera.pos.y,
		};

		transform = (typeof(transform)){
			inv_det * (data->camera.plan_front.y * sprite.x - data->camera.plan_front.x * sprite.y),
			inv_det * (-data->camera.plan_right.y * sprite.x + data->camera.plan_right.x * sprite.y)
		};

		v_move_screen = data->map.sprites.sprites[data->camera.sprite_order[i]].v_move / transform.y;

		sprite_screen_x = (int)((data->map.resolution.x / 2) * (1 + transform.x / transform.y));
		// SpriteHeight
		sprite_res.y = abs((int)(data->map.resolution.y / transform.y)) / data->map.sprites.sprites[data->camera.sprite_order[i]].v_div;

		draw_start.y = -sprite_res.y / 2 + data->map.resolution.y / 2 + v_move_screen;
		if (draw_start.y < 0)
			draw_start.y = 0;
		draw_end.y = sprite_res.y / 2 + data->map.resolution.y / 2 + v_move_screen;
		if (draw_end.y >= data->map.resolution.y)
			draw_end.y = data->map.resolution.y - 1;

		// SpriteWidth
		sprite_res.x = abs((int)(data->map.resolution.y / transform.y)) / data->map.sprites.sprites[data->camera.sprite_order[i]].u_div;
		draw_start.x = -sprite_res.x / 2 + sprite_screen_x;
		if (draw_start.x < 0)
			draw_start.x = 0;
		draw_end.x = sprite_res.x / 2 + sprite_screen_x;
		if (draw_end.x >= data->map.resolution.x)
			draw_end.x = data->map.resolution.x - 1;

		stripe.x = draw_start.x;
		while (stripe.x < draw_end.x)
		{
			tex.x = (int)(256 * (stripe.x - (-sprite_res.x / 2 + sprite_screen_x)) * tex_res.x / sprite_res.x) / 256;

			if (transform.y > 0 && stripe.x > 0 && stripe.x < data->map.resolution.x && transform.y < data->camera.ZBuffer[stripe.x])
			{
				stripe.y = draw_start.y;
				while (stripe.y < draw_end.y)
				{
					int d = (stripe.y - v_move_screen) * 256 - data->map.resolution.y * 128 + sprite_res.y * 128;
					tex.y = ((d * tex_res.y) / sprite_res.y) / 256;

					if (tex.x >= 0 && tex.x < tex_res.x && tex.y >= 0 && tex.y < tex_res.y)
					{
						uint32_t color = get_color(&data->map.textures[IDX_SPRITE].image, tex, tex_res.x);
						if ((color & 0x00FFFFFF) != 0)
							set_color(data, stripe, color);
					}
					stripe.y++;
				}
			}
			stripe.x++;
		}
		i++;
	}
}

void	map_texture(t_game *data, int x)
{
	const int h = data->map.resolution.y;
	uint32_t    color;
	t_texture   *texture;
	int         y;

	// Texture choosing
	texture = &data->map.textures[texture_choser(data)];
	// texture = &data->map.textures[IDX_NORTH];
    
	// Calculate value of wallX, wallX is the exact position of where the wall was hit
	if (data->camera.side == 0)
		data->camera.wallX = data->camera.pos.y + data->camera.perp_wall_dist * data->camera.ray_dir.y;
	else
		data->camera.wallX = data->camera.pos.x + data->camera.perp_wall_dist * data->camera.ray_dir.x;
	data->camera.wallX -= floor(data->camera.wallX);
	
	// Calculating x coordinate of the texture
	data->camera.tex.x = (int)(data->camera.wallX * (double)texture->width);
	
	if (data->camera.side == 0 && data->camera.ray_dir.x > 0)
		data->camera.tex.x = texture->width - data->camera.tex.x - 1;
	if (data->camera.side == 1 && data->camera.ray_dir.y < 0)
		data->camera.tex.x = texture->width - data->camera.tex.x - 1;

	// How much to increase the texture coordinate per screen pixel
	data->camera.tex_step = 1.0 * texture->height / data->camera.line_height;
	// Starting texture coordinate
	data->camera.tex_pos = (data->camera.draw_start - h / 2 + data->camera.line_height / 2) * data->camera.tex_step;
	y = data->camera.draw_start;
	while (y < data->camera.draw_end)
	{
		data->camera.tex.y = (int)data->camera.tex_pos & (texture->height - 1);
		data->camera.tex_pos += data->camera.tex_step;
		color = get_color(&texture->image, data->camera.tex, texture->height);
		if (data->camera.side == 1)
			color = (color >> 1) & 8355711;
		set_color(data, (t_vec){x, y}, color);
		y++;
	}
}

void	get_side(t_game *data)
{
	if (data->camera.ray_dir.x < 0)
	{
		data->camera.step.x = -1;
		data->camera.side_dist.x = (data->camera.pos.x - data->camera.map_pos.x) * data->camera.delta_dist.x;
	}
	else
	{
		data->camera.step.x = 1;
		data->camera.side_dist.x = (data->camera.map_pos.x + 1.0 - data->camera.pos.x) * data->camera.delta_dist.x;
	}
	if (data->camera.ray_dir.y < 0)
	{
		data->camera.step.y = -1;
		data->camera.side_dist.y = (data->camera.pos.y - data->camera.map_pos.y) * data->camera.delta_dist.y;
	}
	else
	{
		data->camera.step.y = 1;
		data->camera.side_dist.y = (data->camera.map_pos.y + 1.0 - data->camera.pos.y) * data->camera.delta_dist.y;
	}
}

static void    perform_dda(t_game *data)
{
	while (TRUE)
	{
		if (data->camera.side_dist.x < data->camera.side_dist.y)
		{
			data->camera.side_dist.x += data->camera.delta_dist.x;
			data->camera.map_pos.x += data->camera.step.x;
			data->camera.side = 0;
		}
		else
		{
			data->camera.side_dist.y += data->camera.delta_dist.y;
			data->camera.map_pos.y += data->camera.step.y;
			data->camera.side = 1;
		}
		if (is_wall(data->map.map[data->camera.map_pos.y][data->camera.map_pos.x]))
			return ;
	}
}

static void    get_perp_dist(t_game *data)
{
	const int	h = data->map.resolution.y;
	//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)

	if (data->camera.side == 0)
		data->camera.perp_wall_dist = (data->camera.map_pos.x - data->camera.pos.x + (1 - data->camera.step.x) / 2) / data->camera.ray_dir.x;
	else
		data->camera.perp_wall_dist = (data->camera.map_pos.y - data->camera.pos.y + (1 - data->camera.step.y) / 2) / data->camera.ray_dir.y;

	data->camera.line_height = (int)(h / data->camera.perp_wall_dist);
	//calculate lowest and highest pixel to fill in current stripe
	data->camera.draw_start = -data->camera.line_height / 2 + h / 2;
	if (data->camera.draw_start < 0)
		data->camera.draw_start = 0;
	data->camera.draw_end = data->camera.line_height / 2 + h / 2;
	if (data->camera.draw_end >= h)
		data->camera.draw_end = h - 1;
}

static void    init_raycast_variables(t_game *data, int x)
{
		//calculate ray position and direction
    data->camera.cameraX = 2 * x / (double)data->map.resolution.x - 1;
	
    data->camera.ray_dir.x = data->camera.plan_front.x + data->camera.plan_right.x * data->camera.cameraX;
    data->camera.ray_dir.y = data->camera.plan_front.y + data->camera.plan_right.y * data->camera.cameraX;

    //which box of the map we're in
    data->camera.map_pos = to_vec(data->camera.pos);
    
	// Check if not 0, so we do not divide by zero
    data->camera.ray_dir.x = (data->camera.ray_dir.x == 0) ? 1 : data->camera.ray_dir.x;
    data->camera.ray_dir.y = (data->camera.ray_dir.y == 0) ? 1 : data->camera.ray_dir.y;
	
    //calculate step and initial sideDist
    data->camera.delta_dist.x = fabs(1 / data->camera.ray_dir.x);
    data->camera.delta_dist.y = fabs(1 / data->camera.ray_dir.y);
}

void	raycasting(t_game *data)
{
	int			x;

	x = 0;
	while (x < data->map.resolution.x)
	{
		init_raycast_variables(data, x);
		get_side(data);
		perform_dda(data);
		get_perp_dist(data);
		map_texture(data, x);
		data->camera.ZBuffer[x] = data->camera.perp_wall_dist;
		x++;
	}
	cast_sprites(data);
}