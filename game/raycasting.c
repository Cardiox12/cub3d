/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 23:14:30 by tony              #+#    #+#             */
/*   Updated: 2020/05/18 16:51:13 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "render.h"

// MARK: To remove
#include <stdio.h>

void	map_texture(t_game *data, int x)
{
	const int h = data->map.resolution.y;
	uint32_t    color;
	t_texture   *texture;
	int         text_num;
	int         y;

	// Texture choosing
	text_num = data->map.map[data->camera.map_pos.y][data->camera.map_pos.x] - '0' - 1;
	texture = &data->map.textures[text_num];
    
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
		// color = texture->image.img_data_addr[texture->height * data->camera.tex.y + data->camera.tex.x];
        
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
	uint32_t	color;
	// t_vec		draw;
	int			x;

	x = 0;
	color = 0;
	while (x < data->map.resolution.x)
	{
		init_raycast_variables(data, x);
		get_side(data);
		perform_dda(data);
		get_perp_dist(data);
		map_texture(data, x);
		x++;
	}
}
