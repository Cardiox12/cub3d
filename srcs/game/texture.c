/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 21:22:12 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 21:31:22 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	compute_wall_x(t_game *data)
{
	if (data->camera.side == 0)
		data->camera.wall_x = data->camera.pos.y + data->camera.perp_wall_dist
		* data->camera.ray_dir.y;
	else
		data->camera.wall_x = data->camera.pos.x + data->camera.perp_wall_dist
		* data->camera.ray_dir.x;
	data->camera.wall_x -= floor(data->camera.wall_x);
}

static void	compute_tex(t_game *data, t_texture *texture)
{
	const int h = data->map.resolution.y;

	data->camera.tex.x = (int)(data->camera.wall_x * (double)texture->width);
	if (data->camera.side == 0 && data->camera.ray_dir.x > 0)
		data->camera.tex.x = texture->width - data->camera.tex.x - 1;
	if (data->camera.side == 1 && data->camera.ray_dir.y < 0)
		data->camera.tex.x = texture->width - data->camera.tex.x - 1;
	data->camera.tex_step = 1.0 * texture->height / data->camera.line_height;
	data->camera.tex_pos = (data->camera.draw_start - h / 2
	+ data->camera.line_height / 2) * data->camera.tex_step;
}

void		map_texture(t_game *data, int x)
{
	uint32_t	color;
	t_texture	*texture;
	int			y;

	texture = &data->map.textures[texture_choser(data)];
	compute_wall_x(data);
	compute_tex(data, texture);
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
